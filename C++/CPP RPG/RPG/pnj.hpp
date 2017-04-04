/**
 * @file pnj.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef PNJ_H
#define PNJ_H
#include "mission.hpp"
#include "personnage.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** \brief Classe représentant les PNJ (personnes non joueurs).
 */
 
class PNJ : public Personnage
{
public:

 /** \brief Constructeur par défaut.
 */ 
  PNJ ();
 
/** \brief Constructeur de la classe PNJ. 
 *  \param intelp La valeur de l'intelligence du PNJ.
 *  \param forcep La valeur de la force du PNJ. 
 *  \param agep L'âge du PNJ. 
 *  \param nomp Le nom du PNJ.
 *  \param miss Le vecteur des missions proposées par les PNJ.
 *  \param dpd Le dialogue par défaut du PNJ
 */   
  PNJ (int intelp, int forcep, int agep, string nomp, vector<Mission*> miss, string dpd);

private:

  	vector<Mission*> missionsP; //!< Le vecteur des missions proposées par les PNJ.
  	string dialogueParDefaut; //!< Le dialogue par défaut du PNJ.


public:

 
  /** \brief stock la valeur de la variable new_var dans la variable MissionsP.
*/  	
    void setMissionsP (vector<Mission*> new_var); 

/** \brief Accède à la variable MissionP.
* \return Un vecteur de missions.
*/ 	
	vector<Mission*> getMissionsP ();

/** \brief Accède à la variable dialogueParDefaut.
* \return Le dialogue par défaut du PNJ.
*/ 	
	string getDialogueParDefaut ();

  /** \brief stock la valeur de la variable dpd dans la variable DialogueParDefaut.
*/ 	
	void setDialogueParDefaut (string dpd);

/** \brief Accède à la variable NomPNJ.
* \return Le nom du PNJ.
*/ 		
	string getNomPNJ();

  /** \brief stock la valeur de la variable nomp dans la variable NomPNJ.
*/ 	
	void setNomPNJ(string nomp);

};

#endif // PNJ_H
