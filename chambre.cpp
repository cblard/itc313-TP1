/** 
  * Fichier:  chambre.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe Chambre
  */

#include "chambre.h"
#include <string>
using namespace std;

Chambre::Chambre(type typeChambre, float prixNuit) : m_type(typeChambre), m_prixNuit(prixNuit) {
	m_id=0;
}

int Chambre::getID(){
	return m_id;
}

string Chambre::getType(){
	switch(m_type){
	case Single: return "Single"; break;
	case Double: return "Double"; break;
	case Suite: return "Suite"; break; 
	default: return "Non reconnu"; break;
	} 
}

float Chambre::getPrixNuit(){
	return m_prixNuit;
}

void Chambre::modifierChambre(float prixNuit){
	m_prixNuit=prixNuit;
}