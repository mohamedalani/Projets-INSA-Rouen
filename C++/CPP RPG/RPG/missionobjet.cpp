#include "missionobjet.hpp"

#include "jeu.hpp"
#include "pnj.hpp"
#include "heros.hpp"
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
				( std::ostringstream() << std::dec << x ) ).str()

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
MissionObjet::MissionObjet(){}
MissionObjet::MissionObjet(int accIntel,int accForce,int accAge, int accEnergie, string nom, int recCash, string dialogueR, string dialogueE, Objet objRec, Objet objATrouver): Mission(accIntel,accForce,accAge,accEnergie,nom, dialogueR, dialogueE){
	recompCash = recCash;
	recompObjet = objRec;
	objetATrouver = objATrouver;
	}

 void MissionObjet :: setRecompCash (int new_var)   {
      recompCash = new_var;
  }

  int MissionObjet :: getRecompCash ()   {
    return recompCash;
  }

  void MissionObjet :: setRecompObjet (Objet new_var){
      recompObjet = new_var;
  }

  Objet MissionObjet :: getRecompObjet ()   {
    return recompObjet;
  }

  string MissionObjet::executerMission(Jeu jeu, Heros *heros, PNJ *pnj){
	  if(jeu.demanderBoolUtilisateur(getTexteMission())) {
	  if (getEtatMission() != enCours){
		  setEtatMission(enCours);
		  if (heros->getEnergie()> accessEnergie) {
			  heros->setEnergie(heros->getEnergie()-accessEnergie);
		  	  jeu.timer(3,"Nouvelle mission : vous avez perdu "+SSTR(accessEnergie)+" d'énergie.");

		  }
		  else {
			  return "Vous n'avez pas assez d'énergie, dommage.";
		  }

	  }
	  else jeu.timer(4,pnj->getNom()+" : Alors, tu as retrouvé : ("+objetATrouver.getNomObjet()+") ?\n Vous cherchez dans votre sac...");

	  	map<string,Objet*> sacHeros = heros->getSac();

	  	if (sacHeros[objetATrouver.getNomObjet()]->getQuantiteObjet()>0){

	  		sacHeros[objetATrouver.getNomObjet()]->setQuantiteObjet(sacHeros[objetATrouver.getNomObjet()]->getQuantiteObjet()-1);

	  		sacHeros[recompObjet.getNomObjet()]->setQuantiteObjet(sacHeros[recompObjet.getNomObjet()]->getQuantiteObjet()+1);

	  		heros->setSac(sacHeros);
  			setEtatMission(achevee);
  			heros->setCash(heros->getCash()+recompCash);
  			jeu.timer(3,"Vous avez obtenu "+SSTR(recompCash)+" cash et l'objet suivant : ("+recompObjet.getNomObjet()+")");
  			return dialogueReussite;
	  	}

	  	else {
	  		return dialogueEchec;
	  	}
	  }
	  else {
		  jeu.timer(3,"Reviens me voir si tu changes d'avis");
		  return "";
	  }
  }
