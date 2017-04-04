/**
 * @file missioncombat.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef MISSIONCOMBAT_H
#define MISSIONCOMBAT_H
#include "mission.hpp"

class Personnage;
class Heros;
class PNJ;
class Jeu;
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/** \brief Classe représentant les missions de type combat.
 */
 
class MissionCombat : public Mission
{


private:

  int recompForce; //!< La valeur de la récompense force que l'héros peut gagner. 
  int recompCash; //!< La valeur de la récompense cash que l'héros peut gagner. 

public: 

 /** \brief Constructeur par défaut.
 */ 
	MissionCombat();

/** \brief Constructeur de la classe mission combat . 
 *  \param accIntel La valeur nécessaire d'intelligence pour accéder à une mission.
 *  \param accForce La valeur nécessaire de la force pour accéder à une mission. 
 *  \param accAge La valeur nécessaire d'âge pour accéder à une mission.
 *  \param accessEnergie La valeur nécessaire d'énergie pour accéder à une mission.  
 *  \param nom le nom de la mission.
 *  \param recForce La valeur de la récompense force que l'héros peut gagner.  
 *  \param recCash La valeur de la récompense cash que l'héros peut gagner
 *  \param dialogueR Le dialogue en cas de réussite. 
 *  \param dialogueE Le dialogue en cas d'échec.    
 */
	MissionCombat(int accIntel,int accForce,int accAge, int accEnergie ,string nom, int recForce, int recCash, string dialogueR, string dialogueE);
  
 /** \brief stock la valeur de la variable new_var dans la variable recompForce.
*/  	
  	void setRecompForce (int new_var);
  	
/** \brief Accède à la variable recompForce.
* \return la valeur de la récompense force.
*/  	
	int getRecompForce ();

 /** \brief stock la valeur de la variable new_var dans la variable recompCash.
*/	
	void setRecompCash (int new_var);
	
/** \brief Accède à la variable recompCash.
* \return la valeur de la récompense cash.
*/  	
	int getRecompCash ();
	
 /** \brief Teste la validité de la mission combat.
* \param heros Un paramètre de la classe Heros.
* \param pnj Un paramètre de la classe PNJ. 
* \return Un booléen. 
*/	
	bool testValidite(Heros *heros, PNJ *pnj);

 /** \brief Compare les statistiques du héros avec celles du PNJ.
* \param heros Un paramètre de la classe Heros.
* \param pnj Un paramètre de la classe PNJ. 
* \return Un personnage qui peut être soit l'héros soit le PNJ. 
*/	
    Personnage* comparerStats(Heros *hero, PNJ *pnj);
    
 /** \brief Exécute une mission de type combat.
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Heros.
* \param pnj Un pointeur sur la classe PNJ. 
* \return Un texte permettant de savoir si le héros a assez de force pour combattre, s'il a gagné ou perdu le combat etc. 
*/    
    string executerMission(Jeu jeu, Heros *heros, PNJ *pnj);

	
};
#endif // MISSIONCOMBAT_H
