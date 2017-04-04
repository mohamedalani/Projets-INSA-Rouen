#include "missioncombat.hpp"

#include "heros.hpp"
#include "pnj.hpp"
#include "jeu.hpp"
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include <iostream>
#include <string>
#include <vector>

using namespace std;
MissionCombat::MissionCombat(){}
MissionCombat::MissionCombat(int accIntel,int accForce,int accAge, int accEnergie ,string nom, int recForce, int recCash, string dialogueR, string dialogueE): Mission(accIntel,accForce,accAge,accEnergie,nom, dialogueR, dialogueE) {
	recompForce = recForce;
	recompCash = recCash;
	}

  void MissionCombat :: setRecompForce (int new_var)   {
      recompForce = new_var;
  }

  int MissionCombat :: getRecompForce ()   {
    return recompForce;
  }

  void MissionCombat :: setRecompCash (int new_var)   {
      recompCash = new_var;
  }

  int MissionCombat :: getRecompCash ()   {
    return recompCash;
  }

  Personnage* MissionCombat::comparerStats(Heros *heros, PNJ *pnj){
	if(heros->getForce() > pnj->getForce())
		return heros;
	else return pnj;
  }

  bool MissionCombat::testValidite(Heros *heros, PNJ *pnj) {
	  if (comparerStats(heros,pnj)->getNom() == (heros->getNom()) )
		return true;
	  else return false;
  }

  string MissionCombat :: executerMission(Jeu jeu, Heros *heros, PNJ *pnj) {

	  if(heros->getEnergie()<=accessEnergie)
		  return "Vous n'avez pas assez d'énergie... C'est peut être mieux comme ça remarquez.";

	  else if(jeu.demanderBoolUtilisateur("Voulez vous combattre "+pnj->getNom()+" ?")) {
			setEtatMission(enCours);
			heros->setEnergie(heros->getEnergie()-accessEnergie);
			jeu.afficherTexte("Vous avez perdu "+SSTR(accessEnergie)+" d'énergie.");
			jeu.timer(1, pnj->getNom()+" se retrousse les manches.");
			jeu.timer(5, "Des coups pleuvent dans tous les sens, le combat fait rage...");
		  if (testValidite(heros, pnj)){
			  setEtatMission(achevee);
			  heros->setCash(heros->getCash()+recompCash);
			  heros->setForce(heros->getForce()+recompForce);
		  	  return pnj->getNom()+" : "+getDialogueReussite()+"\nVous avez gagné le combat, quelle musculature incroyable, je vous croquerai bien...hum. Vous gagnez : "+SSTR(recompCash)+" de cash et "+SSTR(recompForce)+" de force";
		  }
		  else {
			  if (heros->getEnergie()>heros->getForce()/3)
			heros->setEnergie(heros->getEnergie()-(heros->getForce()/3));
			  else heros->setEnergie(0);

			  if (heros->getCash() > recompCash*2)
			heros->setCash(heros->getCash()-recompCash*2);
			  else heros->setCash(0);
			return pnj->getNom()+" : "+getDialogueEchec()+"\nVotre échec vous a épuisé, vous perdez : "+SSTR((heros->getForce()/3))+" points d'énergie et "+SSTR(recompCash*2)+" cash";
		  }
	  }
      else return "La fuite peut parfois être une sage décision... Poule mouillée.";
  }


