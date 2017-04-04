/**
 * @file ecole.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/

#ifndef ECOLE_H
#define ECOLE_H
#include "objet.hpp"
#include "lieu.hpp"
class Heros;
class PNJ;
class Jeu;
class Ville;
#include <string>
#include <vector>
#include <map>

using namespace std;

/** \brief Classe représentant l'école.
 */
class Ecole : public Lieu
{
public:

 /** \brief Constructeur par défaut.
 */ 
	Ecole ();
	
/** \brief Constructeur de la classe Ecole. 
 *  \param objetsDispo Le vecteur des objets disponibles à l'école.
 *  \param cashCache Le cash caché à l'école. 
 *  \param listePNJ La liste des PNJ présents à l'école.  
 *  \param nomLieu c'est le nom du lieu ou se trouve l'héros ici c'est l'école.
 *  \param actionVec Le vecteur d'actons possibles à l'école.
 */
	Ecole (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec) ;



public:

 /** \brief Exécute une action parmi les actions possibles dans le lieu ecole comme parler à un PNJ, Faire du sport, Fouiller, Afficher sac ou Afficher stats du héros. 
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Héros.
* \param ville Un pointeur sur la classe Ville. 
*/
	
	void executerAction(Jeu jeu, Heros *heros, Ville *ville);

};

#endif // ECOLE_H

