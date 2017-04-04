/**
 * @file personnage.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/** \brief Classe représentant les personnages.
 */

class Personnage
{

protected:
	int intelligence; //!< La valeur de l'intelligence du personnage. 
  	int force; //!< La valeur de la force du personnage. 
  	int age; //!< L'âge du personnage. 
	string nom; //!< Le nom du personnage. 

public:

 /** \brief Constructeur par défaut.
 */  
 
  	Personnage ();

/** \brief Constructeur de la classe personnage. 
 *  \param intelp La valeur de l'intelligence du personnage.
 *  \param forcep La valeur de la force du personnage. 
 *  \param agep L'âge du personnage. 
 *  \param nomp le nom du personnage.
 */  	
	Personnage(int intelp,int forcep, int agep, string nomp);

 /** \brief stock la valeur de la variable new_var dans la variable Intelligence.
*/	 	
  	void setIntelligence (int new_var);

/** \brief Accède à la variable Intelligence.
* \return La valeur de l'intelligence.
*/ 	
	int getIntelligence ();

  /** \brief stock la valeur de la variable new_var dans la variable Force.
*/		
  	void setForce (int new_var);

/** \brief Accède à la variable Force.
* \return La valeur de la force.
*/  	
  	int getForce ();

  /** \brief stock la valeur de la variable new_var dans la variable Age.
*/	
	void setAge (int new_var);

/** \brief Accède à la variable Age.
* \return La valeur de l'âge.
*/ 	
	int getAge ();

  /** \brief stock la valeur de la variable var dans la variable Nom.
*/	
	void setNom(string var);

/** \brief Accède à la variable Nom.
* \return Le nom.
*/ 	
	string getNom();

};

#endif // PERSONNAGE_H
