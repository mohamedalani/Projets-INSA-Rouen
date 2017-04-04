// sert à transformer un int en string
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
				( std::ostringstream() << std::dec << x ) ).str()

#include "foret.hpp"
#include "pnj.hpp"
#include "heros.hpp"
#include "jeu.hpp"
#include "ville.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

Foret::Foret () {}
Foret::Foret (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec)	: Lieu (objetsDispo, cashCache, listePNJ, "Foret", actionVec){
	}

//	void Foret::afficherLieu (){
//	cout << "Vous etes dans la foret "<< endl << "Vous pouvez parler avec" << endl;
//	for( int i=0; i < listePNJ.size(); i++)
//		{cout << listePNJ.at(i).getNomPNJ()<<endl;}
//	cout << "Il y a des objets dispo ci dessous, veuillez fouiller !" << endl;
//	for(int i=0; i < objetsDispo.size();i++)
//		{cout << objetsDispo.at(i).getNomObjet()<<endl;}
//	cout << "Dans ce foret, le montant de cash dispo est "<< endl;
//	cout << cashForet << endl;
//	}
	
	
	void Foret::executerAction(Jeu jeu, Heros *heros, Ville *ville) {

		int i=0, entree = -1 ;
	while (entree!=i+3) {

		jeu.afficherTexte( "Vous êtes dans le lieu suivant : " + nomLieu + ". Que voulez-vous faire ? (entrée attendue : un numéro)" );


		for (i=0 ; i < listePNJ.size(); i++) {

		jeu.afficherTexte(SSTR(i) + ". Parler à la personne suivante :" + listePNJ.at(i).getNom() );
		}

		jeu.afficherTexte(SSTR(i) + ". " + "Fouiller" );

		jeu.afficherTexte(SSTR(i+1) + ". " + "Afficher Sac" );

		jeu.afficherTexte(SSTR(i+2) + ". " + "Afficher Stats du Héros" );

		jeu.afficherTexte(SSTR(i+3) + ". " + "Quitter" );



		entree = jeu.demanderEntreeUtilisateur("Faites votre choix :");
		while (entree < 0 or entree > i+3) {
			entree = jeu.demanderEntreeUtilisateur("Faites un choix CORRECT :");
		}

		if ( entree >= 0 and entree < i )
			jeu.afficherTexte( heros->ParleAPNJ(&listePNJ.at(entree), jeu) ) ;

		else if ( entree == i ){

			fouiller(jeu, heros);

		}

		else if ( entree == i+1 ){

			jeu.consommersac(heros);

		}

		else if ( entree == i+2 ){

			jeu.affichageStatsHero(*heros);

		}

		else if ( entree == i+3 ){
			jeu.timer(4, "retour à la ville");
			heros->setLieuActuel(ville);

		}

		else {}


	}
	
	
	}



