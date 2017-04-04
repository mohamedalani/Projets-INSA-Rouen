/**
 * @file ville.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef VILLE_H
#define VILLE_H

#include "lieu.hpp"
#include <string>
#include <vector>
class Heros;
class Jeu;

using namespace std;

/** \brief Classe représentant la ville.
 */
class Ville : public Lieu {

private :
	vector<Lieu*> lieuVec; //!< Le vecteur des lieux possibles.
	
public : 

 /** \brief Constructeur par défaut.
 */ 
	Ville();
	
 /** \brief Constructeur de la classe ville.
* \param lieuVec Le vecteur des lieux possibles.
*/
	Ville(vector<Objet> objetsDispo, int cashCache, vector<PNJ> listePNJ, string nomLieu, vector<string> actionVec, vector<Lieu*> lieuVec);

 /** \brief Exécute une action parmi les actions possibles.
* \param jeu Un paramètre de la classe Jeu.
* \param heros un paramètre de la classe Heros.
*/
	void executerAction(Jeu jeu, Heros *heros, Ville *ville);

 /** \brief Initialise la ville.
*/
	void initialiserVille();

//	void setLieux (vector<Lieu> lieux);
//	vector<Lieu> getLieux ();
//	void ajouterLieu(Lieu lieu);

/** \brief Accède à la variable lieuVec.
* \return le vecteur des lieux possibles.
*/
	const vector<Lieu*>& getLieuVec() const;

 /** \brief stock la valeur de la variable & lieuVec dans la variable lieuVec.
*/
	void setLieuVec(const vector<Lieu*>& lieuVec);
};
#endif // VILLE_H

