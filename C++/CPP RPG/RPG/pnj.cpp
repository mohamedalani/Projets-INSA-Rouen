#include "pnj.hpp"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

PNJ::PNJ () {}

PNJ::PNJ (int intelp, int forcep, int agep, string nomp, vector<Mission*> miss, string dpd):Personnage(intelp,forcep,agep,nomp){

	missionsP = miss;
	dialogueParDefaut= dpd;
	}

  void PNJ::setNomPNJ(string nomp){
	nom = nomp;
}
  string PNJ::getNomPNJ(){
	return nom;
}

  void PNJ::setMissionsP (vector<Mission*> new_var)   {
      missionsP = new_var;
  }

  vector<Mission*> PNJ::getMissionsP ()   {
    return missionsP;
  }
  
  string PNJ::getDialogueParDefaut () {
	return dialogueParDefaut;
  }
  
  void PNJ::setDialogueParDefaut (string dpd){
	dialogueParDefaut = dpd;
  }
