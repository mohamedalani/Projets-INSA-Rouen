#include "personnage.hpp"
#include <string>
#include <vector>
#include <iostream>
 

Personnage::Personnage () {}

Personnage::Personnage(int intelp, int forcep, int agep, string nomp){
	intelligence = intelp;
	force = forcep;
	age = agep;
	nom = nomp;
	}
  void Personnage::setNom(string var){
	nom = var;
}
 string Personnage::getNom(){
	return nom;
}
  void Personnage::setIntelligence (int new_var)   {
      intelligence = new_var;
  }

  int Personnage::getIntelligence ()   {
    return intelligence;
  }

  void Personnage::setForce (int new_var)   {
      force = new_var;
  }

  int Personnage::getForce ()   {
    return force;
  }

  void Personnage::setAge (int new_var)   {
      age = new_var;
  }

  int Personnage::getAge ()   {
    return age;
  }
