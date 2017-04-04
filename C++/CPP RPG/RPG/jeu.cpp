#include <iostream>
#include <string>
#include <vector>

#define INTELDEBUT 6
#define FORCEDEBUT 5
#define CASHDEBUT 20
#define ENERGIE 20

#define INTELFIN 50
#define FORCEFIN 20

#include "jeu.hpp"
#include "heros.hpp"
#include "lieu.hpp"
#include "objet.hpp"
#include "consommable.hpp"
#include "nonconsommable.hpp"
#include "mission.hpp"
#include "missionmaths.hpp"
#include "missionobjet.hpp"
#include "missioncombat.hpp"
#include "personnage.hpp"
#include "pnj.hpp"
#include "objet.hpp"
#include "banque.hpp"
#include "ville.hpp"
#include "superette.hpp"
#include "foret.hpp"
#include "ecole.hpp"

#include <cstdlib>
#include <sstream>
#include <time.h>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


using namespace std;


int main(){

srand(time(NULL));
Jeu jeu;
map<string,Objet*> sac;
vector<Objet> vectObj;
vector<PNJ> vectPnj;
vector<string> vectS; //pas vraiment utile en fait
vector<Lieu*> vectLieu;
vector<Mission*> vectMissionHeros;
vector<Mission*> vectMission;

PNJ fanny(10,11,2,"fanny",vectMission,"hello, je suis fanny");

Objet obj;


/* -----------------------Initialisation de Superette--------------------*/

vector<Objet> vectObjetSuperette;

//Missions
vector<Mission*> vectMissionVendeuse;

NonConsommable stylo(0, 5, "stylo", 0, 500, 5);
NonConsommable styloSac(0, 5, "stylo", 0, 0, 5);
sac["stylo"] = &styloSac;
vectObjetSuperette.push_back(stylo);

NonConsommable caillou(0,0,"caillou",1,500,1);
NonConsommable caillouSac(0,0,"caillou",1,0,1);
sac["caillou"] = &caillouSac;
vectObjetSuperette.push_back(caillou);

Consommable sucette(0,5,"sucette",0,500,1,0);
Consommable sucetteSac(0, 0,"sucette", 0, 0, 1, 0);
sac["sucette"] = &sucetteSac;
vectObjetSuperette.push_back(sucette);



MissionObjet miss1(1 /*accIntel*/,  1 /*accForce*/,  0 /*accAge*/, 3 /*accEnergie*/, "j'ai perdu mon stylo, je ne pourrais plus faire mes comptes !! retrouve le, une récompense t'attend !!" /*texteMission*/, 5 /* recCash*/, "Bravo !!!" /*dialogueR*/, "Tu n'as pas mon stylo :'( reviens quand tu l'auras trouvé" /*dialogueE*/, sucette /*objRec*/, stylo /*objATrouver*/);
vectMissionVendeuse.push_back(&miss1);

// PNJ
PNJ vendeuse(10,30,30,"Jeannette la vendeuse", vectMissionVendeuse, "Bienvenue à la supérette ! Jetez un coup d'oeil aux objets à vendre, je suis sûre que quelques uns pourraient vous intéresser.");
vector<PNJ> vectPNJSuperette;
vectPNJSuperette.push_back(vendeuse);

//Objets
map<string,Objet> objAvendre;

Consommable pain(0, 10, "pain", 0, 500, 5, 0);
Consommable painSac(0, 10, "pain", 0, 3, 5, 0);
sac["pain"]= &painSac;
objAvendre["pain"]= pain;

Consommable potionForce(14, 200, "potion de force", 5, 500, 0, 0);
Consommable potionForceSac(14, 200, "potion de force", 5, 0, 0, 0);
sac["potion de force"]=&potionForceSac;
objAvendre["potion de force"]= potionForce;

Consommable potionIntel(14, 200, "potion de force", 0, 500, 0, 5);
Consommable potionIntelSac(14, 200, "potion d'intelligence", 0, 0, 0, 5 );
sac["potion d'intelligence"]=&potionIntelSac;
objAvendre["potion d'intelligence"]=potionIntel;

NonConsommable epee(15, 300, "épee", 10, 500, 3);
NonConsommable epeeSac(15, 300, "épee", 10, 0, 3);
sac["épee"]=&epeeSac;
objAvendre["épee"]=epee;


//Supérette
Superette superette(vectObjetSuperette, 50, vectPNJSuperette, "superette", vectS, objAvendre );

vector<QCM> qcm2;
QCM q3;
q3.exo= "Combien d'objets sont disponibles à la vente ?";
q3.answer = objAvendre.size();
qcm2.push_back(q3);
MissionMaths miss2(0 /*accessintel*/ , 0 /*accForce*/,0 /*accAge*/, 3 /*accEnergie*/ ,"Au secours ! Mon ordinateur a crashé !! Pourrais-tu compter le nombre d'objets que j'ai en vente ? Je te donnerai un précieux conseil."/*nom*/, 1 /*recIntel*/, "Mercii tu me sauves mon magasin ! Je te conseille de faire un peu de sport avant d'essayer de combattre les voyous de la Forêt..." /*dialogueR*/, "Tu ne sais même pas compter ?? CHAUUUD..." /*dialogueE*/);
miss2.setQuestion(qcm2);

/*----------------------Initialisation de Banque ------------------------*/

PNJ banquier(40,5,25,"Banko le banquier", vectMission, "Bienvenue à la banque ! Ici vous pouvez déposer et retirer de l'argent en toute sécurité.");
vector<PNJ> vectPNJBanque;
vectPNJBanque.push_back(banquier);
Banque banque(vectObjetSuperette, 50,vectPNJBanque, "banque", vectS );

/*----------------------Initialisation de Forêt ------------------------*/

MissionCombat miss3(0,5,12,3,"Viens te battre, amateur",3,25,"Pfff...","Tu es très faible, wow");
vector<Mission*> vectMissionVoyou1;
vectMissionVoyou1.push_back(&miss3);
MissionCombat miss4(0,7,12,4,"Viens te battre, amateur",4,40,"Pfff...","Tu es très faible, wow");
vector<Mission*> vectMissionVoyou2;
vectMissionVoyou2.push_back(&miss4);
MissionCombat miss5(0,10,12,5,"Viens te battre, amateur",5,60,"Pfff...","Tu es très faible, wow");
vector<Mission*> vectMissionVoyou3;
vectMissionVoyou3.push_back(&miss5);
MissionCombat miss6(0,15,12,6,"Viens te battre, amateur",6,100,"Pfff, bravo tu peux te considérer comme un voyou de la galaxie...","Tu es très faible, wow");
vector<Mission*> vectMissionVoyou4;
vectMissionVoyou4.push_back(&miss6);

PNJ voyou1(5, 10,15,"voyou des rues",vectMissionVoyou1, "Wesh t'as un problème ou quoi ?");
PNJ voyou2(5, 15,15,"voyou des champs",vectMissionVoyou2, "Wesh tu veux te battre ou quoi ?");
PNJ voyou3(5, 20,15,"voyou des villes",vectMissionVoyou3, "Wesh c'est quoi ton problème ?");
PNJ voyou4(5, 25,15,"voyou de la galaxie",vectMissionVoyou4, "Wesh tu veux morfler ?");
vector<PNJ> vectPNJForet;
vectPNJForet.push_back(voyou1);
vectPNJForet.push_back(voyou2);
vectPNJForet.push_back(voyou3);
vectPNJForet.push_back(voyou4);

Foret foret(vectObjetSuperette, 50, vectPNJForet, "forêt", vectS);

/*----------------------Initialisation de Ecole ------------------------*/

vector<QCM> qcm3;
QCM q4,q5;
q4.exo= "5x-10=0, que vaut x ?";
q4.answer=2;
q5.exo= "3x-3=-3, que vaut x ?";
q5.answer=0;
qcm3.push_back(q4);
qcm3.push_back(q5);
MissionMaths miss7(5 /*accessintel*/ , 0 /*accForce*/,5 /*accAge*/, 4 /*accEnergie*/ ,"Bonjour, voici une question que je vous propose :"/*nom*/, 2 /*recIntel*/, "Bravo !" /*dialogueR*/, "wow t'es nul" /*dialogueE*/);
vector<Mission*> vectMissionPNJprof;
miss7.setQuestion(qcm3);
vectMissionPNJprof.push_back(&miss7);

PNJ prof(50,20,40,"professeur",vectMissionPNJprof, "Bonjour, jeune élève.");
vector<PNJ> vectPNJEcole;
vectPNJEcole.push_back(prof);

Ecole ecole(vectObjetSuperette, 50, vectPNJEcole, "Ecole", vectS);



/*----------------------Initialisation de Ville --------------------------*/
vectLieu.push_back(&superette);
vectLieu.push_back(&banque);
vectLieu.push_back(&foret);
vectLieu.push_back(&ecole);


Ville ville(vectObj, 5, vectPnj, "Ville", vectS, vectLieu);



/*----------------------Initialisation de Heros --------------------------*/
vectMissionHeros.push_back(&miss1);
vectMissionHeros.push_back(&miss2);
vectMissionHeros.push_back(&miss3);
vectMissionHeros.push_back(&miss4);
vectMissionHeros.push_back(&miss5);
vectMissionHeros.push_back(&miss6);
vectMissionHeros.push_back(&miss7);


Heros heros(INTELDEBUT /*intelh*/, FORCEDEBUT /*forceh*/, 10 /*ageh*/, CASHDEBUT /* cashh*/ , ENERGIE /*energieh*/, sac /*map<string,Objet>*/, "heros", vectMissionHeros, &ville);

/*-------------------------------------- Boucle principale --------------------------------------*/
jeu.jouer(&heros, &ville);




/*------------------------------- TESTS UNITAIRES  -----------------------*/

vector<QCM> qcm1;
QCM q1,q2;
q1.exo= "5x-10=0, que vaut x ?";
q1.answer=2;
q2.exo= "3x-3=-3, que vaut x ?";
q2.answer=0;
qcm1.push_back(q1);
qcm1.push_back(q2);
MissionMaths missM1(5 /*accessintel*/ , 0 /*accForce*/,0 /*accAge*/, 10 /*accEnergie*/ ,"Bonjour, voici une mission que je vous propose :"/*nom*/, 2 /*recIntel*/, "Bravo !" /*dialogueR*/, "wow t'es nul" /*dialogueE*/);

MissionObjet m2(5 /*accIntel*/,  0 /*accForce*/,  0 /*accAge*/, 10 /*accEnergie*/, "j'ai perdu mon stylo, retrouve le !!" /*texteMission*/, 5 /* recCash*/, "Bravo !!!" /*dialogueR*/, "Tu n'as pas mon style :'( reviens quand tu l'auras trouvé" /*dialogueE*/, obj /*objRec*/, stylo /*objATrouver*/);

MissionCombat m3(5, 0, 0, 5, "Combat", 5, 5, "Pff t'es plus fort que moi", "MOUHAHAHA je t'ai tellement défoncé !!");

vector<Mission*> vectMission1;
missM1.setQuestion(qcm1);
vectMission1.push_back(&missM1);
cout<<vectMission1.at(0)->executerMission(jeu, &heros, &fanny)<<endl;
cout<<missM1.executerMission(jeu, &heros, &fanny)<<endl;
cout<<m3.executerMission(jeu, &heros, &fanny)<<endl;
cout<<m2.executerMission(jeu, &heros, &fanny)<<endl;




}

void Jeu::jouer(Heros *heros, Ville* ville){

	while(heros->getIntelligence() < INTELFIN || heros->getForce() < FORCEFIN ){
		heros->getLieuActuel()->executerAction(*this, heros, ville);
	}

	if(heros->getIntelligence()>=INTELFIN ){
		afficherTexte("Bravo, vous avez terminé le jeu, vous avez atteint "+SSTR(INTELFIN)+" d'intelligence, vous avez le droit à une banane !");
	}
}


Jeu::Jeu(){

}

void Jeu::initialiserJeu(){

} 

bool Jeu::demanderBoolUtilisateur(string texte) {

        string s;
        int l;

        bool isInt=false;

        cout<<texte<<endl<<"1 : oui, 0 : non"<<endl;
        do {
            cin>>s;
            istringstream istr(s);
            isInt=(istr>>l);
            if (!isInt or !(l==0 or l==1))
                cout << "Entrée incorrecte, veuillez recommencer." << endl ;
        }while (!isInt or !(l==0 or l==1));

        if (l==0)
            return false;
        else if (l==1)
            return true;
        else{}

}


int Jeu::demanderEntreeUtilisateur(string texte) {
	string s;
	int l;
	bool isInt=false;
	cout<<texte<<endl;

	do {
		cin>>s;
		istringstream istr(s);
		isInt=(istr>>l);
		if (!isInt)
			cout << "Entrée incorrecte, veuillez recommencer." << endl ;
	}
	while (!isInt);

	return l;
}

string Jeu::demanderStringUtilisateur(string texte) {
	cout<<texte<<endl;
	string l;
	cin>>l;
	return l;
}

void Jeu::afficherTexte(string texte) {
	cout<<texte<<endl;
}

void Jeu::affichersac(Heros* heros){
        string s ;
        map <string, Objet*> sacH=heros->getSac();

        for(map<string,Objet*>::iterator it=sacH.begin(); it!=sacH.end(); ++it) {
        	if(it->second->getQuantiteObjet()>0) {
                this->afficherTexte("- (" + SSTR(it->second->getQuantiteObjet()) + ")"
+ it->first + "\n" );
                }

        }
}


void Jeu::consommersac(Heros* heros){
        this->afficherTexte("Voici les objets dans le sac");
        this->affichersac(heros);
        if (demanderBoolUtilisateur("Consommer un objet ?")){
        map<string,Objet*> sac = heros->getSac();
        string choix1;
        do{
         choix1 = this->demanderStringUtilisateur("Faites votre choix (écrivez le nom de l'objet tel qu'il est orthographié) ou 'q' pour quitter.");

         if (choix1=="q") {return;}
         else if(sac.find(choix1) == sac.end())
                                   {this->afficherTexte("Veuillez choisir un objet consommable");}
        }while(sac.find(choix1) == sac.end() && choix1!="q");

         bool choix2 = this->demanderBoolUtilisateur("Consommer?" );
                 if(choix2 == 1){

                         sac[choix1]->setQuantiteObjet(sac[choix1]->getQuantiteObjet()-1);
                         heros->setSac(sac);


                         sac[choix1]->utiliserObjet(*this,heros);
                 }else
                         this->afficherTexte("Vous avez choisi de ne pas consommer objet");
        }
        else return;

}


void Jeu::timer(int temps, string message){
	time_t timer;
	double t =time(&timer);
	afficherTexte(message);
	int i=1;
	while(time(&timer)-t<temps) {
		if (time(&timer)-t == i){
			cout<<"."<<endl;
			i++;
		}
	}
	return;
}

void Jeu:: affichageStatsHero(Heros heros){
	this->afficherTexte("Voici vos stats: Energie : " + SSTR(heros.getEnergie()) + "\n" + "Intelligence : " + SSTR(heros.getIntelligence()) + "\n" + "Cash : " + SSTR(heros.getCash()) + "\n" + "Force : " + SSTR(heros.getForce()) + "\n" + "Age : " + SSTR(heros.getAge()));
	timer(4,"");
}
