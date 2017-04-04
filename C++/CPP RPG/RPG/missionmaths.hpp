/**
 * @file missionmaths.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef MISSIONMATHS_H
#define MISSIONMATHS_H
#define NOMBREQUESTION 3 // Nombre de question dans le vecteur de question


#include "mission.hpp"
class Heros;
class Jeu;
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

struct QCM{
	string exo;
	int answer;
};

/** \brief Classe représentant les missions de type maths.
 */
 
class MissionMaths : public Mission
{


private:

  int recompInt; //!< La valeur de la récompense intelligence que l'héros peut gagner. 
  vector<QCM> question; //!< Le vecteur des questions composé de l'exercice et la réponse. 
  int niveau; //!< Le niveau de la mission.  
  
public:

 /** \brief Constructeur par défaut.
 */  
	MissionMaths();

/** \brief Constructeur de la classe mission maths.
 *  \param heros Un paramètre de la classe Heros.  
 *  \param accIntel La valeur nécessaire d'intelligence pour accéder à une mission.
 *  \param accForce La valeur nécessaire de la force pour accéder à une mission. 
 *  \param accAge La valeur nécessaire d'âge pour accéder à une mission.
 *  \param accessEnergie La valeur nécessaire d'énergie pour accéder à une mission.  
 *  \param nom le nom de la mission.
 *  \param recIntel La valeur de la récompense intelligence que l'héros peut gagner.  
 *  \param dialogueR Le dialogue en cas de réussite. 
 *  \param dialogueE Le dialogue en cas d'échec.    
 */
 	MissionMaths(int accIntel,int accForce,int accAge, int accEnergie ,string nom, int recIntel, string dialogueR, string dialogueE);

 /** \brief stock la valeur de la variable new_var dans la variable recompInt.
*/  
  	void setRecompInt (int new_var);
  	
/** \brief Accède à la variable recompInt.
* \return la valeur de la récompense intelligence.
*/  	
	int getRecompInt ();
	
 /** \brief stock la valeur de la variable new_var dans la variable question.
*/  	
	void setQuestion (vector<QCM> new_var);

/** \brief Accède à la variable question.
* \return Le vecteur des questions composé de l'exercice et la réponse.
*/  	
	vector<QCM> getQuestion ();

/** \brief Accède à la variable nomMission.
* \return Le nom de la mission.
*/ 	
	string getNomMission();

 /** \brief stock la valeur de la variable var dans la variable nomMission.
*/ 	
	void setNomMission(string var);

 /** \brief Exécute une mission de type maths.
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Heros.
* \param pnj Un pointeur sur la classe PNJ. 
* \return Un message permettant de savoir si le héros a réussi ou échoué la mission maths et combien de points d'intelligence a-t-il gagné etc. 
*/ 	
	string executerMission(Jeu jeu, Heros *heros, PNJ *pnj);
	
};
#endif 
