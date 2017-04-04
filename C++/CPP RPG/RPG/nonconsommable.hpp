
/**
 * @file nonconsommable.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef NONCONSOMMABLE_H
#define NONCONSOMMABLE_H
#include "objet.hpp"
#include "heros.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Jeu;

/** \brief Classe représentant les objets non consommables.
 */
class NonConsommable : public Objet
{
public:

 /** \brief Constructeur par défaut.
 */  
  NonConsommable();
  
/** \brief Constructeur de la classe nonconsommable. 
 *  \param accObjet L'accessibilité de l'objet à partir d'un certain âge.
 *  \param p Le prix de l'objet. 
 *  \param nomObj Le nom de l'objet. 
 *  \param vf La valeur de la force que l'héros peut gagner
 *  \param qteObj La quantité de l'objet.
 *  \param durVie La durée de vie de l'objet. 
 */
  NonConsommable (int accObjet, int p, string nomObj, int vf, int qteObj, int durVie);

private:


  int dureevie; //!< La valeur de la durée de vie de l'objet non consommable.


public:

 /** \brief stock la valeur de la variable new_var dans la variable dureevie.
*/
  	void setdureevie (int new_var);

/** \brief Accède à la variable dureevie.
* \return La durée de vie de l'objet non consommable.
*/ 
	int getdureevie ();

/** \brief Utilise un objet non consommable afin de gagner de la force.
* \param jeu Une instance de la classe Jeu.
* \param heros un pointeur sur la classe Heros
*/ 
	void utiliserObjet(Jeu jeu, Heros* heros);
};

#endif // NONCONSOMMABLE_H

