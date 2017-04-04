/**
 * @file foret.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef FORET_H
#define FORET_H
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

/** \brief Classe représentant la foret.
 */
class Foret : public Lieu
{
public:

 /** \brief Constructeur par défaut.
 */ 
	Foret ();
	
 /** \brief Constructeur de la classe foret.
 *  \param objetsDispo Le vecteur des objets disponibles dans la foret.
 *  \param cashcache La valeur du cash caché dans la foret.
 *  \param listePNJ Le vecteur des PNJ présents dans la foret.
 *  \param nomLieu Le nom de la foret.
 *  \param actionVec Le vecteur des actions possibles dans la foret.
 */
	Foret (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec) ;

private:
	


public:


 /** \brief Exécute une action parmi les actions possibles comme parler à un PNJ, Fouiller, Afficher sac, Afficher stats du héros. 
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Heros.
* \param ville Un pointeur sur la classe Ville. 
*/	
	void executerAction(Jeu jeu, Heros *heros, Ville *ville);

};

#endif // FORET_H

