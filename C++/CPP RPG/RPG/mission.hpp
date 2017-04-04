/**
 * @file mission.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/
#ifndef mission
#define mission

#include <string>
#include <vector>

class Jeu;
class Heros;
class PNJ;

using namespace std;
enum EtatMission { pasEntamee, enCours, achevee };

/** \brief Classe représentant les missions.
 */
 
class Mission
{

protected:
  int accessIntel; //!< La valeur nécessaire d'intelligence pour accéder à une mission. 
  int accessForce; //!< La valeur nécessaire de la force pour accéder à une mission. 
  int accessAge; //!< La valeur nécessaire d'âge pour accéder à une mission. 
  int accessEnergie; //!< La valeur nécessaire d'énergie pour accéder à une mission. 
  EtatMission etatMission; //!< L'état de chaque mission pour savoir si la mission est pasEntamee, enCours ou achevée. 
  string texteMission; //!< Le texte envoyé à l'utilisateur afin qu'il fasse son choix. 
  static int compteurMission; //!< Le compteur de la mission. 
  string dialogueReussite; //!< Un texte renvoyé à l'utilisateur quand celui-ci réussit la mission. 
  string dialogueEchec; //!< Un texte renvoyé à l'utilisateur quand celui-ci échoue la mission. 



public:

/** \brief Constructeur de la classe mission. 
 *  \param accIntel La valeur nécessaire d'intelligence pour accéder à une mission.
 *  \param accForce La valeur nécessaire de la force pour accéder à une mission. 
 *  \param accAge La valeur nécessaire d'âge pour accéder à une mission.
 *  \param accessEnergie La valeur nécessaire d'énergie pour accéder à une mission.  
 *  \param nom le nom de la mission.
 *  \param dialogueR Le dialogue en cas de réussite. 
 *  \param dialogueE Le dialogue en cas d'échec.    
 */

  Mission(int accIntel,int accForce,int accAge, int accEnergie ,string nom, string dialogueR, string dialogueE);
  
 /** \brief Constructeur par défaut.
 */ 
   
  Mission();
 
 /** \brief Destructeur par défaut.
 */ 
  
  ~Mission();

/** \brief stock la valeur de la variable new_var dans la variable accessIntel.
*/ 
  void setAccessIntel (int new_var);
  
/** \brief Accède à la variable accessIntel.
* \return la valeur de l'intelligence nécessaire pour accèder à une mission.
*/  
  int getAccessIntel ();
  
/** \brief stock la valeur de la variable new_var dans la variable accessForce.
*/   
  void setAccessForce (int new_var);
  
/** \brief Accède à la variable accessForce.
* \return la valeur de la force nécessaire pour accèder à une mission.
*/  
  int getAccessForce ();
  
/** \brief stock la valeur de la variable new_var dans la variable accessAge.
*/ 
  void setAccessAge (int new_var);
  
/** \brief Accède à la variable accessAge.
* \return la valeur de l'âge nécessaire pour accèder à une mission.
*/  
  int getAccessAge ();
  
/** \brief stock la valeur de la variable new_var dans la variable etatMission.
*/ 
  void setEtatMission (EtatMission new_var);

/** \brief Accède à la variable etatMission.
* \return L'état de la mission par exemple pasEntame, enCours ou achevee.
*/   
  EtatMission getEtatMission ();
  
/** \brief stock la valeur de la variable new_var dans la variable texteMission.
*/ 
  void setTexteMission (string new_var);
  
/** \brief Accède à la variable texteMission.
* \return Le texte permettant de choisir une mission par l'utilisateur .
*/
  string getTexteMission ();

/** \brief stock la valeur de la variable var dans la variable accessEnergie.
*/ 
  void setAccessEnergie(int var);
  
/** \brief Accède à la variable accessEnergie.
* \return la valeur de l'énergie nécessaire pour accèder à une mission.
*/  
  int getAccessEnergie();
  
/** \brief Accède à la variable dialogueReussite.
* \return Un texte afin d'indiquer si la mission a été réussie.
*/ 
  string getDialogueReussite();

/** \brief stock la valeur de la variable dialogueReussite dans la variable dialogueReussite.
*/ 
  void setDialogueReussite(string dialogueReussite);

/** \brief Accède à la variable dialogueEchec.
* \return Un texte afin d'indiquer si la mission a été échouée.
*/ 
  string getDialogueEchec();

 /** \brief Exécute une mission. C'est une méthode virtuelle qui va être redéfinie dans chacune des classes filles de Mission.
* \param jeu Une instance de la classe Jeu.
* \param heros Un pointeur sur la classe Heros.
* \param pnj Un pointeur sur la classe PNJ. 
* \return erreur si la mission n'a pas été exécutée. 
*/
  virtual string executerMission(Jeu jeu, Heros *heros, PNJ *pnj);

};

#endif // MISSION_H
