/**
 * @file superette.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef SUPERETTE_H
#define SUPERETTE_H
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

/** \brief Classe représentant la superette.
 */
class Superette : public Lieu
{
public:

 /** \brief Constructeur par défaut.
 */ 
	Superette ();
	
 /** \brief Constructeur de la classe superette. 
 *  \param objetsDispo Le vecteur des objets disponibles dans la superette.
 *  \param cashcache La valeur du cash caché dans la superette. 
 *  \param listePNJ Le vecteur des PNJ présents dans la superette. 
 *  \param nomLieu Le nom de la superette.
 *  \param actionVec Le vecteur des actions possibles dans la superette.
 *  \param objetsAVendre Un map des objets à vendre dans la superette.
 */
	Superette (vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec, map<string, Objet> objetsAVendre) ;

private:
	
	map<string, Objet> objetsAVendre; //!< Le map des objets à vendre dans la superette.

public:

//	void afficherLieu ();

 /** \brief Exécute une action parmi les actions possibles.
* \param jeu Un paramètre de la classe Jeu.
* \param heros un paramètre de la classe Heros.
*/	
	void executerAction(Jeu jeu, Heros *heros, Ville *ville);

 /** \brief Achète un objet parmi les objets disponibles dans la superette.
* \param objet Un paramètre de la classe Objet.
* \param heros un paramètre de la classe Heros.
*/		
	void acheterUnObjet(Heros *heros, Objet objet);

 /** \brief Vend un objet parmi les objets disponibles dans le sac.
* \param objet Un paramètre de la classe Objet.
* \param heros un paramètre de la classe Heros.
*/		
	void vendreUnObjet(Heros *heros, Objet objet);

/** \brief Accède à la variable objetsAVendre.
* \return Le map des objets à vendre.
*/	  	
	const map<string, Objet>& getObjetsAVendre() const;

 /** \brief stock la valeur de la variable & objetsAVendre dans la variable objetsAVendre.
*/	
	void setObjetsAVendre(const map<string, Objet>& objetsAVendre);


};

#endif // SUPERETTE_H

