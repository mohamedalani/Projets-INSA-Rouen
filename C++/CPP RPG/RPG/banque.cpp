// sert à transformer un int en string
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
				( std::ostringstream() << std::dec << x ) ).str()

#include "banque.hpp"
#include "heros.hpp"
#include "jeu.hpp"
#include "pnj.hpp"
#include "ville.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


Banque::Banque () {this->cashBanque = 0 ;}
Banque::Banque (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec):Lieu(objetsDispo, cashCache, listePNJ, "Banque", actionVec){
	this->cashBanque = 0 ;}

//	void Banque::afficherLieu (){
//	cout << "Vous êtes bien dans la banque "<< endl << "Vous pouvez parler avec" << endl;
//	for( int i=0; i < listePNJ.size(); i++)
//		{cout << listePNJ.at(i).getNomPNJ()<<endl;}
//	cout << "Les objets disponibles dans la banque sont les suivants : " << endl;
//	for(int i=0; i < objetsDispo.size();i++)
//		{cout << objetsDispo.at(i).getNomObjet()<<endl;}
//	cout << "Le montant du cash disponible sur votre compte est "<< endl;
//	cout << cashBanque << endl;
//	}

  	void Banque::setCashBanque (int CashBanque)   {
         	cashBanque = CashBanque;
  }

  	int Banque::getCashBanque ()   {
		return cashBanque;
  }

	
	void Banque::deposerCash (Heros *heros, int cash) {
  		if (heros->getCash() >= cash) {
  			cashBanque+=cash;
  			heros->setCash(heros->getCash() - cash);

  		}
  		else {}
  }
	
	void Banque::retirerCash(Heros *heros, int cash){
		if (cashBanque >= cash) {
			cashBanque-=cash;
			heros->setCash(heros->getCash() + cash);

		}
		else {}

	}

	Banque::~Banque(){}

	void Banque::executerAction(Jeu jeu, Heros *heros, Ville *ville) {

		int i=0, entree = -1 ;

	while (entree!=i+5) {

		jeu.afficherTexte( "Vous êtes dans le lieu suivant : " + nomLieu + ". Que voulez-vous faire ? (entrée attendue : un numéro)" );


		for (i=0 ; i < listePNJ.size(); i++) {
			jeu.afficherTexte(SSTR(i) + ". Parler à la personne suivante :" + listePNJ.at(i).getNom() );
		}

		jeu.afficherTexte(SSTR(i) + ". " + "Déposer" );

		jeu.afficherTexte(SSTR(i+1) + ". " + "Retirer" );

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

			entree = -1 ;

			while ( entree < 0 or entree > heros->getCash() ) {
				entree = jeu.demanderEntreeUtilisateur("Votre cash en portefeuille s'élève à : " + SSTR(heros->getCash()) + ". Combien voulez-vous déposer ? Entrez 0 pour annuler");
			}

			deposerCash(heros, entree);
			jeu.afficherTexte("Cash déposé: " + SSTR(entree) + ". Nouveau cash en banque: " + SSTR(cashBanque) + ". Nouveau cash en portefeuille: " + SSTR(heros->getCash()));

		}

		else if ( entree == i+1 ){

			entree = -1 ;

			while ( entree < 0 or entree > cashBanque ) {
				entree = jeu.demanderEntreeUtilisateur("Votre cash en banque s'élève à : " + SSTR(cashBanque) + ". Combien voulez-vous retirer ? Entrez 0 pour annuler");
			}

			retirerCash(heros, entree);
			jeu.afficherTexte("Cash retiré: " + SSTR(entree) + ". Nouveau cash en banque: " + SSTR(cashBanque) + ". Nouveau cash en portefeuille: " + SSTR(heros->getCash()));


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
			jeu.timer(4, "retourn à la ville");
			heros->setLieuActuel(ville);

		}

		else {}

	}
	}








