/**
 * @file heros.hpp
 * @version 1.0
 * @date 05/05/2015
 * @author ALANI-DARCISSAC-EL JIBBAWE-WANG
*/

#ifndef HEROS_H
#define HEROS_H
#include "objet.hpp"
#include "lieu.hpp"
#include "personnage.hpp"
class PNJ; 
class Mission; 
class Personnage;
class Consommable;
class NonConsommable;
class MissionCombat;
class MissionObjet;
class MissionMaths;
class Jeu; 
#include <string>
#include <vector>
#include <map>

using namespace std;

/** \brief Classe représentant l'héros.
 */

class Heros : public Personnage
{

private:
          int cash; //!< La valeur du cash de l'héros.
          int energie; //!< La valeur de l'énergie de l'héros. 
          map<string, Objet*> sac; //!< Le sac d'objets que l'héros possède.
          vector<Mission*> missions; //!< Le vecteurs des missions disponibles.
          Lieu *lieuActuel; //!< Le lieu actuel du héros.
public:

 /** \brief Constructeur par défaut.
 */
        Heros ();
        
/** \brief Constructeur de la classe Heros. 
 *  \param intelh La valeur de l'intelligence de l'héros.
 *  \param forceh La valeur de la force de l'héros. 
 *  \param ageh L'âge de l'héros.
 *  \param cashh La valeur du cash de l'héros.  
 *  \param energieh La valeur de l'énergie de l'héros.
 *  \param sach Le sac d'objets de l'héros.
 *  \param nomh Le nom de l'héros.
 *  \param missh Le vecteur missions de l'héros.
 *  \param lieuh Un pointeur sur la classe Lieu. 
 */
        Heros(int intelh,int forceh, int ageh, int cashh , int energieh, map<string,Objet*>sach, string nomh, vector<Mission*> missh, Lieu* lieuh);
        
/** \brief Retourne les missions disponibles proposées par les PNJ.
  * \param pnj Un pointeur sur la classe PNJ. 
  * \return Le vecteur des missions disponibles.
*/       
        vector<Mission*> missionDisponible(PNJ *pnj);
        
/** \brief Gère le déplacement de l'héros.
  * \param lieu Un pointeur sur la classe Lieu. 
*/  
        void seDeplacer(Lieu *lieu);

public:


 /** \brief Sort la mission la plus adaptée à l'héros en fonction de ces statistiques.
* \param miss Un vecteur de missions.
* \return Un pointeur sur la classe Mission. 
*/        
        Mission* missionPlusaccess(vector<Mission*> miss);
        
/** \brief stock la valeur de la variable new_var dans la variable cash.
*/
        void setCash (int new_var);

/** \brief Accède à la variable cash.
* \return La valeur du cash de l'héros.
*/ 	       
        int getCash ();

/** \brief stock la valeur de la variable var dans la variable energie.
*/
        
        void setEnergie (int new_var);
 
 /** \brief Accède à la variable energie.
* \return La valeur de l'énergie de l'héros.
*/        
        int getEnergie ();

/** \brief stock la valeur de la variable new_var dans la variable sac.
*/
           
        void setSac (map<string,Objet*> new_var);
 
  /** \brief Accède à la variable sac.
* \return Un map constitué d'objets et leurs noms.
*/       
        map<string,Objet*> getSac ();

/** \brief stock la valeur de la variable new_var dans la variable nomHero.
*/        
        void setNomHero (string new_var);

  /** \brief Accède à la variable nomHero.
* \return Le nom de l'héros.
*/        
        string getNomHero ();

/** \brief stock la valeur de la variable new_var dans la variable missions.
*/         
        void setMissions (vector<Mission*> new_var);

  /** \brief Accède à la variable missions.
* \return Le vecteur des missions de l'héros.
*/          
        vector<Mission*> getMissions ();

/** \brief stock la valeur de la variable new_var dans la variable lieuActuel.
*/        
        void setLieuActuel (Lieu *new_var);

  /** \brief Accède à la variable lieuActuel.
* \return Un pointeur sur lieu.
*/       
        Lieu * getLieuActuel ();

 /** \brief Met en relation l'héros et les PNJ.
* \param pnj Un paramètre de la classe PNJ.
* \param jeu Un paramètre de la classe Jeu.
* \return Un texte afin de gérer la communication entre l'héros et les pnj.
*/         
        string ParleAPNJ(PNJ* pnj,Jeu jeu);


};
#endif
