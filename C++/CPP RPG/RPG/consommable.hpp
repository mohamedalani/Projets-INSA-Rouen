/**
 * @file consommable.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/

#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H
#include "jeu.hpp"
#include "objet.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;



class Jeu;
class Heros;

/** \brief Classe représentant les objets consommables.
 */

class Consommable : public Objet
{
public:

/** \brief Constructeur de la classe Consommable. 
 *  \param accObjet L'accessibilité de l'objet à partir d'un certain âge.
 *  \param p Le prix de l'objet. 
 *  \param nomObj Le nom de l'objet.  
 *  \param vf La valeur force que l'héros gagne en consommant l'objet.
 *  \param qteObj La quantité de l'objet.
 *  \param valeurEnergie La valeur d'énergie que l'héros gagne en consommant l'objet.
 *  \param valeurIntel La valeur d'intelligence que l'héros gagne en consomment l'objet.
 */
 
  Consommable (int accObjet, int p, string nomObj, int vf, int qteObj, int valeurEnergie, int valeurIntel);
 
 /** \brief Constructeur par défaut.
 */ 
  
  Consommable();

private:


  int valeurIntel; //!< La valeur de l'intelligence que l'héros gagne en consommant l'objet.
  int valeurEnergie; //!< La valeur de l'énergie que l'héros gagne en consommant l'objet.

public:

/** \brief stock la valeur de la variable valeurIntel dans la variable valeurIntel.
*/
  	void setValeurIntel (int valeurIntel);

/** \brief Accède à la variable valeurIntel.
* \return La valeur de la variable valeurIntel.
*/
	int getValeurIntel ();

/** \brief stock la valeur de la variable var dans la variable valeurIntel.
*/
	void setValeurEnergie(int var);

/** \brief Accède à la variable valeurEnergie.
* \return La valeur de la variable valeurEnergie.
*/
	int getValeurEnergie();
	
 /** \brief En consommant l'objet, permet à l'héros de gagner de l'énergie, de la force et de l'intelligence.
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Héros.
*/

	void utiliserObjet(Jeu jeu,Heros* heros);

};



#endif // CONSOMMABLE_H
