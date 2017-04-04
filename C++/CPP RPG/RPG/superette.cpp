// sert à transformer un int en string
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
				( std::ostringstream() << std::dec << x ) ).str()

#include "superette.hpp"
#include "pnj.hpp"
#include "heros.hpp"
#include "jeu.hpp"
#include "ville.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

Superette::Superette () {}
Superette::Superette (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec, map<string, Objet> objetsAVendre)	: Lieu (objetsDispo, cashCache, listePNJ, "Superette", actionVec){
	this->objetsAVendre = objetsAVendre;}

//	void Superette::afficherLieu (){
//	cout << "Vous etes dans la superette "<< endl << "Vous pouvez parler avec" << endl;
//	for( int i=0; i < listePNJ.size(); i++)
//		{cout << listePNJ.at(i).getNomPNJ()<<endl;}
//	cout << "Il y a des objets dispo ci dessous, veuillez fouiller !" << endl;
//	for(int i=0; i < objetsDispo.size();i++)
//		{cout << objetsDispo.at(i).getNomObjet()<<endl;}
//	cout << "Dans ce superette, le montant de cash dispo est "<< endl;
//	cout << cashSuperette << endl;
//	}
	
const map<string, Objet>& Superette::getObjetsAVendre() const {
		return objetsAVendre;
	}

	void Superette::setObjetsAVendre(const map<string, Objet>& objetsAVendre) {
		this->objetsAVendre = objetsAVendre;
	}
	
	void Superette::executerAction(Jeu jeu, Heros *heros, Ville *ville) {

		int i=0, entree = -1 ;
	while (entree!=i+5) {

		jeu.afficherTexte( "Vous êtes dans le lieu suivant : " + nomLieu + ". Que voulez-vous faire ? (entrée attendue : un numéro)" );


		for (i=0 ; i < listePNJ.size(); i++) {

		jeu.afficherTexte(SSTR(i) + ". Parler à la personne suivante :" + listePNJ.at(i).getNom() );
		}

		jeu.afficherTexte(SSTR(i) + ". " + "Acheter" );

		jeu.afficherTexte(SSTR(i+1) + ". " + "Vendre" );

		jeu.afficherTexte(SSTR(i+2) + ". " + "Fouiller" );

		jeu.afficherTexte(SSTR(i+3) + ". " + "Afficher Sac" );

		jeu.afficherTexte(SSTR(i+4) + ". " + "Afficher Stats du Héros" );

		jeu.afficherTexte(SSTR(i+5) + ". " + "Quitter" );



		entree = jeu.demanderEntreeUtilisateur("Faites votre choix :");
		while (entree < 0 or entree > i+5) {
			entree = jeu.demanderEntreeUtilisateur("Faites un choix CORRECT :");
		}

		if ( entree >= 0 and entree < i )
			jeu.afficherTexte( heros->ParleAPNJ(&listePNJ.at(entree), jeu) ) ;

		else if ( entree == i ){

			jeu.afficherTexte( "Voici les objets à acheter :" );
			map<std::string,Objet>::iterator iit = objetsAVendre.begin();
			map<std::string,Objet>::iterator iitt = objetsAVendre.end();
			while ( iit != iitt )
			{
				jeu.afficherTexte(	(*iit).first + " - Prix: " +  SSTR((*iit).second.getPrix())	);
				iit++;
			}

			string choixObjet ;

			do {
			choixObjet = jeu.demanderStringUtilisateur("Quel objet voulez-vous acheter ? Ecrivez un objet valide, ou q pour retourner au menu");
			} while ( choixObjet!="q" && objetsAVendre.find(choixObjet) == objetsAVendre.end() );

			if (choixObjet!="q") {
				acheterUnObjet(heros, objetsAVendre[choixObjet]);
				jeu.afficherTexte("Vous avez acheté: " + choixObjet + ". Nouvelle quantité de l'objet: " + SSTR(heros->getSac()[choixObjet]->getQuantiteObjet()) + ". Nouveau cash: " + SSTR(heros->getCash()));
			}

		}

		else if ( entree == i+1 ){

			jeu.afficherTexte( "Voici vos objets que vous pouvez vendre :" );
			map<string, Objet*> sacH = heros->getSac();
			map<string, Objet*>::iterator it = sacH.begin();
			map<string, Objet*>::iterator iitt = sacH.end();
			while ( it != iitt )
			{
				if ((*it).second->getQuantiteObjet() > 0)
					jeu.afficherTexte(	(*it).first + " - Prix: " +  SSTR((*it).second->getPrix())	+ " - Qté restante: " +  SSTR((*it).second->getQuantiteObjet())	);
				it++;
			}

			string choixObjet ;

//			choixObjet = jeu.demanderStringUtilisateur("Quel objet voulez-vous vendre ? Ecrivez un objet valide, ou quitter pour retourner au menu");
//						vendreUnObjet(heros, heros->getSac()[choixObjet]);

			do {
				choixObjet = jeu.demanderStringUtilisateur("Quel objet voulez-vous vendre ? Ecrivez un objet valide, ou q pour retourner au menu");
			} while ( choixObjet!="q" && sacH.find(choixObjet) == sacH.end() );

			if (choixObjet!="q") {
				if ( objetsAVendre[choixObjet].getQuantiteObjet() > 0) {
					vendreUnObjet(heros, *sacH[choixObjet]);
					jeu.afficherTexte("Vous avez vendu: " + choixObjet + ". Nouvelle quantité de l'objet: " + SSTR(sacH[choixObjet]->getQuantiteObjet()) + ". Nouveau cash: " + SSTR(heros->getCash()));

				}
				else jeu.afficherTexte("Vous n'avez pas cet objet");

			}

		}

		else if ( entree == i+2 ){

			fouiller(jeu, heros);

		}

		else if ( entree == i+3 ){

			jeu.consommersac(heros);

		}

		else if ( entree == i+4 ){

			jeu.affichageStatsHero(*heros);

		}

		else if ( entree == i+5 ){
			jeu.timer(4, "retour à la ville");
			heros->setLieuActuel(ville);

		}

		else {}

	}
	}

	
	void Superette::acheterUnObjet(Heros *heros, Objet objet) {

		if ( heros->getCash() >= objet.getPrix() ) {
//			cout<<"jsikskqs "<<heros->getCash()<<endl;
//			cout<<"jsikskqs "<<objet.getPrix()<<endl;
 			heros->setCash ( heros->getCash() - objet.getPrix() ) ;
 			map<string, Objet*> sacH=heros->getSac();
			sacH[objet.getNomObjet()]->setQuantiteObjet( heros->getSac()[objet.getNomObjet()]->getQuantiteObjet()+1 ) ;
			heros->setSac(sacH);
		}
	}
	
	void Superette::vendreUnObjet(Heros *heros, Objet objet) {
		
		if ( heros->getSac()[objet.getNomObjet()]->getQuantiteObjet() > 0 ) {
		
 			heros->setCash ( heros->getCash() + objet.getPrix() ) ;
 			map<string, Objet*> sacH=heros->getSac();
 			sacH[objet.getNomObjet()]->setQuantiteObjet( heros->getSac()[objet.getNomObjet()]->getQuantiteObjet()-1 ) ;
 			heros->setSac(sacH);

		}
	}



