#include "consommable.hpp"
#include "jeu.hpp"
#include "heros.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;
Consommable::Consommable(){}
Consommable::Consommable (int accObjet, int p, string nomObj, int vf, int qteObj, int valEnergie, int valIntel) : Objet(accObjet, p, nomObj, vf, qteObj) {
	valeurIntel = valIntel;
	valeurEnergie = valEnergie;
	}

 void Consommable :: setValeurIntel (int valeurIntel)   {
      this->valeurIntel = valeurIntel;
  }

  int Consommable :: getValeurIntel ()   {
    return valeurIntel;
  }

  void Consommable::setValeurEnergie(int var) {
	valeurEnergie=var;
  }
  int Consommable::getValeurEnergie(){
	return valeurEnergie;
  }
  void Consommable::utiliserObjet(Jeu jeu, Heros* heros){
	  heros->setEnergie(heros->getEnergie()+ valeurEnergie);
	  heros->setIntelligence(heros->getIntelligence() + valeurIntel);
	  heros->setForce(heros->getForce() + valeurForce);
	  jeu.afficherTexte("Vous avez gagné " + SSTR(valeurEnergie) + " En energie et " + SSTR(valeurIntel)  + " En Intelligence");
  }
