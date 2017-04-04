
/**
 * @file objet.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef OBJET_H
#define OBJET_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Heros;
class Jeu;

/** \brief Classe représentant les objets.
 */
class Objet
{

protected:
  int accessObjet; //!< L'âge à partir duquel on peut accèder à l'objet.
  string nomObjet; //!< Le nom de l'objet.
  int prix; //!< Le prix de l'objet.
  int valeurForce; //!< La valeur de la force que l'objet permet de gagner.
  int quantiteObjet; //!< La qunatité de l'objet.


public:

 /** \brief Constructeur par défaut.
 */  
 
	Objet();

/** \brief Constructeur de la classe objet. 
 *  \param accObjet L'accessibilité de l'objet à partir d'un certain âge.
 *  \param p Le prix de l'objet. 
 *  \param nomObj Le nom de l'objet. 
 *  \param vf La valeur de la force que l'héros peut gagner.
 *  \param qteObj La quantité de l'objet.
 */

	Objet(int accObjet, int p, string nomObj, int vf, int qteObj);

 /** \brief stock la valeur de la variable new_var dans la variable nomObjet.
*/	
	void setNomObjet (string new_var);

/** \brief Accède à la variable nomObjet.
* \return Le nom de l'objet.
*/ 	
	string getNomObjet ();

 /** \brief stock la valeur de la variable new_var dans la variable prix.
*/	
	void setPrix (int new_var);

/** \brief Accède à la variable prix.
* \return Le prix de l'objet.
*/ 	
  	int getPrix ();

 /** \brief stock la valeur de la variable new_var dans la variable valeurForce.
*/	
	void setValeurForce (int new_var);

/** \brief Accède à la variable valeurForce.
* \return La valeur de la force que l'héros peut gagner.
*/ 	
	int getValeurForce ();

 /** \brief stock la valeur de la variable var dans la variable accessObjet.
*/		
	void setAccessObjet(int var);

/** \brief Accède à la variable accessObjet.
* \return L'âge à partir duquel l'objet sera accessible.
*/ 	
	int getAccessObjet();

 /** \brief stock la valeur de la variable var dans la variable quantiteObjet.
*/		
	void setQuantiteObjet(int var);

/** \brief Accède à la variable quantiteObjet.
* \return La quantité de l'objet.
*/ 	
	int getQuantiteObjet();

 /** \brief Initialise l'objet.
*/	
	void initialiserObjet();
	
/** \brief sert à utiliser un objet. C'est une méthode virtuelle qui va être redéfinie dans chacune des classes filles de Objet.
* \param jeu Une instance de la classe Jeu.
* \param heros un pointeur sur la classe Heros. 
*/

   virtual void utiliserObjet(Jeu jeu, Heros *heros);

};

#endif // OBJET_H
