// sert à transformer un int en string
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
				( std::ostringstream() << std::dec << x ) ).str()

#include "ecole.hpp"
#include "pnj.hpp"
#include "heros.hpp"
#include "jeu.hpp"
#include "ville.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

Ecole::Ecole () {}
Ecole::Ecole(vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec)	: Lieu (objetsDispo, cashCache, listePNJ, "Ecole", actionVec){
	}

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
	
	
void Ecole::executerAction(Jeu jeu, Heros *heros, Ville *ville) {

		int i=0, entree = -1 ;
	while (entree!=i+4) {

		jeu.afficherTexte( "Vous êtes dans le lieu suivant : Ecole. Que voulez-vous faire ? (entrée attendue : un numéro)" );


		for (i=0 ; i < listePNJ.size(); i++) {

		jeu.afficherTexte(SSTR(i) + ". Parler à la personne suivante :" + listePNJ.at(i).getNom() );
		}
		jeu.afficherTexte(SSTR(i) + ". Faire du sport" );

		jeu.afficherTexte(SSTR(i+1) + ". " + "Fouiller" );

		jeu.afficherTexte(SSTR(i+2) + ". " + "Afficher Sac" );

		jeu.afficherTexte(SSTR(i+3) + ". " + "Afficher Stats du Héros" );

		jeu.afficherTexte(SSTR(i+4) + ". " + "Quitter" );



		entree = jeu.demanderEntreeUtilisateur("Faites votre choix :");
		while (entree < 0 or entree > i+4) {
			entree = jeu.demanderEntreeUtilisateur("Faites un choix CORRECT :");
		}

		if ( entree >= 0 and entree < i )
			jeu.afficherTexte( heros->ParleAPNJ(&listePNJ.at(entree), jeu) ) ;

		else if (entree == i) {
			if (heros->getEnergie()>heros->getEnergie()-4) {
			jeu.timer(40/heros->getForce(),"Vous vous défoulez comme un fou !");
			heros->setForce(heros->getForce()+1);
			heros->setEnergie(heros->getEnergie()-4);
			jeu.timer(1,"Vous êtes épuisés ! Vous avez gagné 2 de force mais perdu 5 en énergie.");

			}
			else jeu.afficherTexte("Vous n'avez pas assez d'énergie... Allez vous reposer");
		}
		else if ( entree == i+1 ){

			fouiller(jeu, heros);

		}

		else if ( entree == i+2 ){

			jeu.consommersac(heros);

		}

		else if ( entree == i+3 ){

			jeu.affichageStatsHero(*heros);

		}

		else if ( entree == i+4 ){
			jeu.timer(4, "retour à la ville");
			heros->setLieuActuel(ville);

		}

		else {}


	}


	}

	


