/**
 * @file banque.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/

#ifndef BANQUE_H
#define BANQUE_H
#include "lieu.hpp"
class Jeu; 
class Heros; 
class Ville;

#include <string>
#include <vector>

/** \brief Classe représentant la banque. */

class Banque : public Lieu
{
public:

 /** \brief Constructeur par défaut.
 */

	Banque();

/** \brief Constructeur de la classe Banque. 
 *  \param objetsDispo Les objets disponibles à la banque.
 *  \param cashcache Le cash caché dans la banque. 
 *  \param listePNJ Les PNJ présents dans la banque.
 *  \param nomLieu Le nom de la banque.  
 *  \param actionVec le vecteur des actions disponibles dans la banque.   
 */

	Banque (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec);
  
 /** \brief Destructeur par défaut.
 */
  
  virtual ~Banque();

private:

int cashBanque; //!< La valeur du cash disponible à la banque. 


public:


/** \brief stock la valeur de la variable CashBanque dans la variable CashBanque.
*/	
  	void setCashBanque (int CashBanque);
  	
/** \brief Incrémente le CashBanque d'une valeur cash de la variable cash.
*/	
	void deposerCash (Heros *heros, int cash);
  	
/** \brief Accède à la variable CashBanque.
* \return La valeur de la variable CashBanque.
*/  	
  	int getCashBanque ();
  	
/** \brief Décrémente le CashBanque d'une valeur cash de la variable cash.
*/	
	void retirerCash(Heros *heros, int cash);

 /** \brief Exécute une action parmi les actions possibles par exemple Déposer, Retirer, Fouiller, Afficher Sac , Afficher stats du héros ou Quitter la banque.
* \param jeu Une instance de la classe Jeu.
* \param heros Une instance de la classe Heros.
*/
	void executerAction(Jeu jeu, Heros *heros, Ville *ville);

};

#endif // BANQUE_H

