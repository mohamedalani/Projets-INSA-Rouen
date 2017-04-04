// sert à transformer un int en string
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
				( std::ostringstream() << std::dec << x ) ).str()


#include "ville.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "jeu.hpp"
#include "heros.hpp"


using namespace std;

Ville::Ville(){}

Ville::Ville(vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec, vector<Lieu*> lieuVec) : Lieu(objetsDispo, cashCache, listePNJ, nomLieu, actionVec){
	this->lieuVec = lieuVec;
}

const vector<Lieu*>& Ville::getLieuVec() const {
	return lieuVec;
}

void Ville::setLieuVec(const vector<Lieu*>& lieuVec) {
	this->lieuVec = lieuVec;
}


void Ville::executerAction(Jeu jeu, Heros* heros, Ville* ville) {

		jeu.afficherTexte( "\nVous êtes dans le lieu suivant : " + nomLieu + ". Que voulez-vous faire ?\n" );

		int i=0 ;
		for (i=0 ; i < lieuVec.size(); i++) {
			jeu.afficherTexte( SSTR(i) + ". Se rendre au lieu suivant :" + this->lieuVec.at(i)->getNomLieu() );
		}
		int entree = -1 ;
		while (entree < 0 or entree > i-1) {
			entree = jeu.demanderEntreeUtilisateur("Faites votre choix :");
		}

		if ( entree >= 0 and entree < i ) {
			jeu.timer(4, "déplacement en cours...");
			heros->setLieuActuel(lieuVec[entree]) ;
		}

		else {}


}


void Ville::initialiserVille(){
	
}

//void Ville::setLieux (vector<Lieu> l){
//	lieux = l;
//}
//
//vector<Lieu> Ville::getLieux (){
//	return lieux;
//}
//
//void Ville::ajouterLieu(Lieu lieu) {
//	lieux.push_back(lieu);
//}


