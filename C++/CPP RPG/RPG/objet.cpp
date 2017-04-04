

#include "objet.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "heros.hpp"
#include "jeu.hpp"
using namespace std;

Objet::Objet(int accObjet, int p, string nomObj, int vf, int qteObj){
	accessObjet = accObjet;
	nomObjet = nomObj;
	prix = p;
	valeurForce = vf;
	quantiteObjet = qteObj;
}
Objet::Objet(){
	}

 void Objet:: setNomObjet (string new_var)   {
      nomObjet = new_var;
  }

  string Objet::getNomObjet ()   {
    return nomObjet;
  }

  void Objet:: setPrix (int new_var)   {
      prix = new_var;
  }

  int Objet:: getPrix ()   {
    return prix;
  }

  void Objet:: setValeurForce (int new_var)   {
      valeurForce = new_var;
  }

  int Objet:: getValeurForce ()   {
    return valeurForce;
  }

  void Objet::setAccessObjet(int var){
	accessObjet =var;
  }
  
  int Objet::getAccessObjet() {
	return accessObjet;
  }
  
  void Objet::setQuantiteObjet(int var) {
    quantiteObjet = var;
  }
  
  int Objet::getQuantiteObjet() {
	return quantiteObjet;
  }

	void initialiserObjet() {
	}

	void Objet::utiliserObjet(Jeu jeu, Heros* heros){
}
