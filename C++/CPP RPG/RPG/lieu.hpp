/**
 * @file lieu.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef LIEU_H
#define LIEU_H
#include "objet.hpp"
#include "pnj.hpp"
class Heros;
class Jeu;
class Ville;
#include <string>
#include <vector>

#include <sstream>

using namespace std;

/** \brief Classe représentant le lieu.
 */
 
class Lieu
{
public:

 /** \brief Constructeur par défaut.
 */
 
  Lieu ();
 
 /** \brief Constructeur de la classe lieu. 
 *  \param objetsDispo Le vecteur des objets disponibles dans un lieu.
 *  \param cashCashe La valeur du cash caché dans un lieu. 
 *  \param listePNJ Le vecteur des PNJ présents dans un lieu.
 *  \param nomLieu Le nom du lieu.  
 *  \param actionVec Le vecteurs des actions.
 */
  Lieu (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec);

 /** \brief Destructeur par défaut.
 */
 
virtual ~Lieu();

protected:

  vector<Objet> objetsDispo; //!< Le vecteur des objets disponibles dans un lieu. 
  int cashCache; //!< La valeur du cash caché dans un lieu. 
  vector<PNJ> listePNJ; //!< La liste des PNJ présents dans un lieu. 
  string nomLieu; //!< Le nom du lieu. 
  vector<string> listeAction; //!< La liste des actions dans un lieu. 

public:

// getters and setters
 
/** \brief stock la valeur de la variable new_var dans la variable objetsDispo.
*/
  void setObjetsDispo (vector<Objet> new_var);

/** \brief Accède à la variable objetsDispo.
* \return Le vecteur des objets disponibles.
*/   
  vector<Objet> getObjetsDispo () const;
 
/** \brief stock la valeur de la variable new_var dans la variable listePNJ.
*/
  void setListePNJ (vector<PNJ> new_var);

/** \brief Accède à la variable listePNJ.
* \return La liste des PNJ.
*/  
  vector<PNJ> getListePNJ () const;

/** \brief stock la valeur de la variable new_var dans la variable nomLieu.
*/
  void setNomLieu (string new_var);

/** \brief Accède à la variable nomLieu.
* \return le nom du lieu.
*/   
  string getNomLieu () const;

/** \brief stock la valeur de la variable new_var dans la variable CashCache.
*/	 
  void setCashCache (int new_var);

/** \brief Accède à la variable CashCache.
* \return La valeur du cash caché.
*/   
  int getCashCache () const;

/** \brief stock la valeur de la variable new_var dans la variable listeAction.
*/	
  void setListeAction (vector<string> new_var);


/** \brief Accède à la variable listeAction.
* \return la liste des actions.
*/ 
  vector<string> getListeAction () const;
  

// on garde?  void initialiserLieu();
// méth virtuelle pure, à implémenter  dans les classes filles

 /** \brief Exécute une action parmi les actions possibles.
* \param jeu Une instance de la classe Jeu.
* \param heros un pointeur sur la classe Heros.
* \param ville Un pointeur sur la classe Ville. 
*/
  virtual void executerAction(Jeu jeu, Heros *heros, Ville *ville);
 
  /** \brief Fouille un lieu afin de trouver des objets en consommant une certaine énergie et en ajoutant ces objets au sac de l'héros. 
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Heros.
*/ 
  void fouiller(Jeu jeu, Heros *heros);
  
};

#endif // LIEU_H
