#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "heros.hpp"
#include "jeu.hpp"
#include "pnj.hpp"
#include "mission.hpp"
#include "missionmaths.hpp"
#include "missioncombat.hpp"
#include "missionobjet.hpp"

#include "consommable.hpp"
#include "nonconsommable.hpp"

using namespace std;

Heros::Heros () {}

Heros::Heros(int intelh,int forceh, int ageh, int cashh , int energieh,
map<string,Objet*> sach, string nomh, vector<Mission*> missh, Lieu *lieuh):Personnage
(intelh,forceh,ageh,nomh){
        cash = cashh;
        energie = energieh;
        sac = sach;
        missions = missh;
        lieuActuel = lieuh; }

string Heros::getNomHero(){
        return nom;
}
void Heros::setNomHero(string nomh){
        nom = nomh;}


vector<Mission*>  Heros::missionDisponible (PNJ *pnj){
vector<Mission*> miss;
for(int i=0; i<pnj->getMissionsP().size(); i++){
        if(pnj->getMissionsP().at(i)->getAccessIntel() <= intelligence
        		&& pnj->getMissionsP().at(i)->getAccessForce () <= force
        		&& pnj->getMissionsP().at(i)->getAccessAge() <= age && pnj->getMissionsP().at(i)->getEtatMission()!=achevee)

            miss.push_back(pnj->getMissionsP().at(i));
        }
return miss;
}

void Heros::seDeplacer (Lieu *lieu){
        lieuActuel = lieu;
}

void Heros::setCash (int new_var)   {
      cash = new_var;
  }

  int Heros::getCash ()   {
    return cash;
  }

  void Heros::setEnergie (int new_var)   {
      energie = new_var;
  }


  int Heros::getEnergie ()   {
    return energie;
  }



  void Heros::setSac (map<string,Objet*> new_var)   {
      sac = new_var;
  }


  map<string,Objet*> Heros::getSac ()   {
    return sac;
  }



  void Heros::setMissions (vector<Mission*> new_var)   {
      missions = new_var;
  }

  vector<Mission*>  Heros::getMissions ()   {
    return missions;
  }

  void Heros::setLieuActuel (Lieu *new_var)   {
      lieuActuel = new_var;
  }


  Lieu* Heros::getLieuActuel ()   {
    return lieuActuel;
  }



Mission* Heros::missionPlusaccess(vector<Mission*> miss){
Mission *min = (miss.at(0));
        for(int i=0; i<miss.size(); i++){
        if(miss.at(i)->getAccessIntel() + miss.at(i)->getAccessForce() +
miss.at(i)->getAccessAge() < min->getAccessIntel() +
min->getAccessForce() + min->getAccessAge())
                min = miss.at(i);}
return min;
}


string Heros::ParleAPNJ(PNJ *pnj,Jeu jeu){
        if(this->missionDisponible(pnj).empty()){
                return pnj->getDialogueParDefaut();}
            else {
            	return this->missionPlusaccess( this->missionDisponible(pnj))->executerMission(jeu, this, pnj);
            }
}
