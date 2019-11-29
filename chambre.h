/** 
  * Fichier:  chambre.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Déclaration de la classe Chambre
  */

#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
using namespace std; 

enum type {Single, Double, Suite} ;

class Chambre{
public:
	Chambre(type typeChambre, float prixNuit);
	int getID();
	string getType();
	float getPrixNuit();
	void modifierChambre(float prixNuit);
	void afficherInfos();
private:
	int m_id;
	type m_type;
	float m_prixNuit;
};

#endif