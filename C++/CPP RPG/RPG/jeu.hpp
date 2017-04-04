/**
 * @file jeu.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef JEU_H
#define JEU_H

#include <string>
#include <vector>
class Heros; 
class Consommable; 
class NonConsommable;
class Mission; 
class MissionMaths; 
class MissionObjets; 
class MissionCombats; 
class Lieu; 
class Personnage; 
class PNJ; 
class Objet; 
class Banque; 
class Ville; 
class Foret;



using namespace std;

/** \brief Classe représentant le jeu.
 */

class Jeu {

	
public : 

/** \brief Constructeur par défaut.
 */ 
	Jeu();

 /** \brief Gère le jeu.
* \param heros Un pointeur sur la classe Heros.
* \param ville Un pointeur sur la classe Ville. 
*/	
	void jouer(Heros *heros, Ville *ville);

 /** \brief Initialise le jeu.
*/
	void initialiserJeu();

 /** \brief Vérifie si les saisies clavier faites par l'utilisateur sont correctes ou pas.
* \param texte Un texte correspondant au choix de l'utilisateur.
* \return un booléen.
*/
	bool demanderBoolUtilisateur(string texte);

 /** \brief Vérifie si les saisies clavier faites par l'utilisateur sont correctes ou pas.
* \param texte Un texte correspondant au choix de l'utilisateur.
* \return un booléen.
*/
	int demanderEntreeUtilisateur(string texte);

 /** \brief Demande une saisie clavier à l'utilisateur sous forme d'un texte.
* \param texte Un texte correspondant à la saisie clavier de l'utilisateur.
* \return un entier.
*/
	string demanderStringUtilisateur(string texte);

 /** \brief Affiche le texte saisi par l'utilisateur.
* \param texte Un texte demandé à l'utilisateur afin qu'il fasse son choix.
*/
	void afficherTexte(string texte);

 /** \brief sert à consommer ou non un objet consommable par le héros.
* \param heros Un pointeur sur la classe Heros.
*/
	void consommersac(Heros* heros);

 /** \brief Affiche le contenu du sac de l'héros.
* \param heros Un pointeur sur la classe Heros.
*/
	void affichersac(Heros* heros);

 /** \brief Gère le temps de déplacement de l'héros entre les différents lieux ou le temps d'une mission.
* \param temps Un temps correspondant à la durée du timer.
* \param message Un texte permettant de savoir ce qui est en train de se passer pendant le temps temps.  
*/
	void timer(int temps, string message);

 /** \brief Affiche les stats de l'héros comme l'énergie, l'intelligence, le cash, la force et l'âge.
* \param heros Une instance de la classe Heros.
*/
	void affichageStatsHero(Heros heros);


};




#endif // JEU_H
