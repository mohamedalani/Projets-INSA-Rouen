#include "nonconsommable.hpp"
#include "jeu.hpp"
#include "heros.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

NonConsommable::NonConsommable(){}

NonConsommable::NonConsommable (int accObjet, int p, string nomObj, int vf, int qteObj, int durVie) : Objet(accObjet, p, nomObj, vf, qteObj) {
	dureevie = durVie;}

 void NonConsommable :: setdureevie (int new_var)   {
      dureevie = new_var;
  }

  int NonConsommable :: getdureevie ()   {
    return dureevie;
  }
  void NonConsommable::utiliserObjet(Jeu jeu,Heros* heros){
	  jeu.afficherTexte("Ce n'est pas un objet consommbale.");
	  heros->setForce(heros->getForce() + valeurForce);


 }
