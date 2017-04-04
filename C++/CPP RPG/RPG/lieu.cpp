#include "lieu.hpp"
#include "heros.hpp"
#include "jeu.hpp"
#include "ville.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;
Lieu::Lieu () {cashCache = 0 ;}

Lieu::~Lieu () {}

Lieu::  Lieu (vector<Objet> objetVec, int cash, vector<PNJ> pnjVec, string lieu, vector<string> actionVec){
	objetsDispo = objetVec;
	cashCache = cash ;
	listePNJ = pnjVec;
	nomLieu = lieu;
	listeAction = actionVec;
  }
	

	void Lieu:: setObjetsDispo (vector<Objet> new_var)   {
      objetsDispo = new_var;
  }


  	vector<Objet> Lieu::getObjetsDispo () const    {
    return objetsDispo;
  }

  	void Lieu::setListePNJ (vector<PNJ> new_var)   {
      listePNJ = new_var;
  }


  	vector<PNJ> Lieu::getListePNJ () const   {
    return listePNJ;
  }

  	void Lieu::setNomLieu (string new_var)   {
      nomLieu = new_var;
  }

  	string Lieu::getNomLieu () const   {
    return nomLieu;
  }
  
   	void Lieu::setCashCache (int new_var)   {
      cashCache = new_var;
  }

  	int Lieu::getCashCache () const   {
    return cashCache;
  }
  
   	void Lieu::setListeAction (vector<string> new_var)   {
      listeAction = new_var;
  }

   	vector<string> Lieu::getListeAction () const   {
    return listeAction;
  }


   	void Lieu::fouiller(Jeu jeu, Heros *heros) {	// pour fouiller le héros doit avoir au moins 3 pts d'énergie
		jeu.timer(5,"Vous fouillez le lieu...");
		if (objetsDispo.size() == 0)
			jeu.afficherTexte("Il n'y a plus rien ici... :'( ");
		else if ( objetsDispo.size()>0 && heros->getEnergie() >= 3 ) {

			srand(time(NULL));
			int nb = rand() % objetsDispo.size() ;
//			cout << "objetsDispo.size() " << objetsDispo.size() << endl;

			map <string, Objet*> sacH = heros->getSac();
			sacH[this->getObjetsDispo().at(nb).getNomObjet()]->setQuantiteObjet(heros->getSac()[objetsDispo.at(nb).getNomObjet()]->getQuantiteObjet()+1 ) ;
			heros->setSac(sacH);

		//	cout << "objetsDispo.begin() + nb " << objetsDispo.begin()+nb << endl;
			jeu.afficherTexte("Bravo ! Votre fouille vous a permis de trouver : "+objetsDispo.at(nb).getNomObjet());
			objetsDispo.erase(objetsDispo.begin()+nb);
			
			heros->setEnergie( heros->getEnergie() - 3 ) ;
			jeu.afficherTexte("Fouiller c'est fatiguant, vous avez perdu 3 d'énergie");

		}
		else if (heros->getEnergie() < 3)
			jeu.afficherTexte("Vous n'avez pas assez d'énergie... Reposez-vous espèce de faible !");

		else {}//end if
		
	}

   	void Lieu::executerAction(Jeu jeu, Heros *heros, Ville *ville){
   		cout<<"erreur";
   	}



