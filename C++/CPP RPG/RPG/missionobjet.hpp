/**
 * @file missionobjet.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef MISSIONOBJET_H
#define MISSIONOBJET_H

#include "mission.hpp"
#include "objet.hpp"

class Jeu;
class PNJ;
class Heros;
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/** \brief Classe représentant les missions de type objet.
 */
 
class MissionObjet : public Mission
{


private:

  Objet recompObjet; //!< L'objet que l'héros peut gagner.
  Objet objetATrouver; //!< L'objet que l'héros doit trouver.
  int recompCash; //!< La valeur de la récompense cash que l'héros peut gagner.
  
public: 

 /** \brief Constructeur par défaut.
 */  
	MissionObjet();
	
/** \brief Constructeur de la classe mission objet. 
 *  \param accIntel La valeur nécessaire d'intelligence pour accéder à une mission.
 *  \param accForce La valeur nécessaire de la force pour accéder à une mission. 
 *  \param accAge La valeur nécessaire d'âge pour accéder à une mission.
 *  \param accessEnergie La valeur nécessaire d'énergie pour accéder à une mission.  
 *  \param nom Le nom de la mission.
 *  \param recCash La valeur de la récompense cash que l'héros peut gagner.   
 *  \param dialogueR Le dialogue en cas de réussite. 
 *  \param dialogueE Le dialogue en cas d'échec.    
 *  \param objRec L'objet que l'héros peut gagner.
 *  \param objATrouver L'objet que l'héros doit trouver.
 */
 
	MissionObjet(int accIntel,int accForce,int accAge, int accEnergie, string nom, int recCash, string dialogueR, string dialogueE, Objet objRec, Objet objATrouver);
  	
 /** \brief stock la valeur de la variable new_var dans la variable recompCash.
*/  	
  	void setRecompCash (int new_var);
	
/** \brief Accède à la variable recompCash.
* \return la valeur de la récompense cash.
*/  	
	int getRecompCash ();
	
 /** \brief stock la valeur de la variable new_var dans la variable recompObjet.
*/ 	
	void setRecompObjet (Objet new_var);

/** \brief Accède à la variable recompObjet.
* \return l'objet correspondant à la récompense objet.
*/ 
	Objet getRecompObjet ();
	
/** \brief Accède à la variable nomMission.
* \return Le nom de la mission.
*/ 
	string getNomMission();

 /** \brief stock la valeur de la variable var dans la variable nomMission.
*/ 	
	void setNomMission(string var);

 /** \brief Exécute une mission de type objet.
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Heros.
* \param pnj Un pointeur sur la classe PNJ. 
* \return Un texte permettant de savoir si le héros a assez d'énergie pour faire ce type de mission, s'il a réussi ou échoué à faire cette mission etc. 
*/ 	
	string executerMission(Jeu jeu, Heros *heros, PNJ *pnj);


	
};
#endif 
