#include "missionmaths.hpp"
#include "heros.hpp"
#include "jeu.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;
MissionMaths :: MissionMaths(){}
MissionMaths :: MissionMaths(int accIntel,int accForce,int accAge, int accEnergie ,string nom, int recIntel, string dialogueR, string dialogueE): Mission(accIntel,accForce,accAge,accEnergie,nom, dialogueR, dialogueE){
	recompInt = recIntel;
	niveau = floor(accessIntel/10);

	}

 void MissionMaths :: setRecompInt (int new_var)   {
      recompInt = new_var;
  }

  int MissionMaths :: getRecompInt ()   {
    return recompInt;
  }

  void MissionMaths :: setQuestion (vector<QCM> new_var)   {
      question = new_var;
  }

  vector<QCM> MissionMaths :: getQuestion ()   {
    return question;
  }

  string MissionMaths::executerMission(Jeu jeu, Heros *heros, PNJ *pnj) {

	  if (heros->getEnergie()> accessEnergie) {

	  if (jeu.demanderBoolUtilisateur("Voulez vous essayer de répondre à une question de niveau "+SSTR(niveau)+" ? Vous gagnerez ainsi "+SSTR(recompInt)+" points d'intelligence" )){
		  setEtatMission(enCours);

			  heros->setEnergie(heros->getEnergie()-accessEnergie);
			  jeu.afficherTexte("Vous venez de perdre "+SSTR(accessEnergie)+" points d'énergie, il vous en reste "+SSTR(heros->getEnergie()));
			  jeu.timer(1,"");
			  jeu.timer(3,pnj->getNom()+" : Laisse moi réfléchir à une question...");

		  bool test = true;
		  for(int i=0; i<question.size() and test==true; i++){
	  		  int entree = jeu.demanderEntreeUtilisateur(question.at(i).exo);
	  		  if (entree != question.at(i).answer) {
	  			  test = false;
	  			  jeu.timer(2,pnj->getNom()+" : Pas du tout ! C'est médiocre ! On s'arrête là.");
	  		  }
	  		  else if (i!= question.size()-1) jeu.timer(3,pnj->getNom()+" : hum... celle là était simple. Laisse moi réfléchir à une autre question.");
	  	  }
	  	  if (test==true) {
	  	  	heros->setIntelligence(heros->getIntelligence()+recompInt);
	  	  	return pnj->getNom()+" : "+getDialogueReussite()+"\nVous avez gagné "+SSTR(recompInt)+" de points d'intelligence";
	  	    }
	  	  else
	  	  	return getDialogueEchec();
	  	  }
	  else return pnj->getNom()+" : Je vois... Vous n'êtes donc pas de taille... Amateur.";
	  }
	  else return "Vous n'avez pas assez d'énergie... Dommage.";
  }


