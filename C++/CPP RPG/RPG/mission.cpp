#include "mission.hpp"
#include "jeu.hpp"
#include "heros.hpp"
#include "pnj.hpp"
#include <iostream>
#include <string>
#include <vector>



using namespace std;


Mission::Mission (int accIntel,int accForce,int accAge, int accEnergie ,string nom, string dialogueR, string dialogueE) {
	accessIntel = accIntel;
	accessForce = accForce;
	accessAge = accAge;
	texteMission = nom;
	accessEnergie = accEnergie;
	etatMission = pasEntamee;
	dialogueReussite = dialogueR;
	dialogueEchec = dialogueE;

}


Mission::Mission(){};

Mission::~Mission(){};

  int Mission::compteurMission = 1;

  void Mission ::setAccessIntel (int new_var)   {
      accessIntel = new_var;
  }

  int Mission :: getAccessIntel ()   {
    return accessIntel;
  }

  void Mission :: setAccessForce (int new_var)   {
      accessForce = new_var;
  }

  int Mission :: getAccessForce ()   {
    return accessForce;
  }

  void Mission ::setAccessAge (int new_var)   {
      accessAge = new_var;
  }

  int Mission :: getAccessAge ()   {
    return accessAge;
  }

  void Mission :: setEtatMission (EtatMission new_var)   {
      etatMission = new_var;
  }


  EtatMission Mission :: getEtatMission ()   {
    return etatMission;
  }

  void Mission :: setTexteMission (string new_var)   {
      texteMission = new_var;
  }

  string Mission :: getTexteMission ()   {
    return texteMission;
  }
  
	string Mission::getDialogueReussite()  {
		return dialogueReussite;
	}

	void Mission::setDialogueReussite(string dialogueReussite) {
		this->dialogueReussite = dialogueReussite;
	}

	string Mission::getDialogueEchec(){
		return dialogueEchec;
	}

  void Mission::setAccessEnergie(int var) {
	accessEnergie = var;
  }
  
  int Mission::getAccessEnergie() {
	return accessEnergie;
  }

  string Mission::executerMission(Jeu jeu, Heros *heros, PNJ *pnj){
	  return "erreur";
  }









