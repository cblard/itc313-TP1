/** 
  * Fichier:  chambre.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe Chambre
  */

#include "chambre.h"
#include <iomanip>
#include <string>
#include <iostream>
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
	default: return "Non reconnu"; break; // On retourne une chaîne de caractères pour pour avoir l'afficher dans un cout 
	} 
}

float Chambre::getPrixNuit(){
	return m_prixNuit;
}

void Chambre::modifierChambre(int type){ // On associe un entier à un type
	switch(type){
		case 1: m_type=Single; m_prixNuit=100; break;
		case 2: m_type=Double; m_prixNuit=125; break;
		case 3: m_type=Suite; m_prixNuit=210; break;
	}
}

void Chambre::afficherInfos(){
	cout<<"Le prix de la chambre est de "<<setprecision(2)<<fixed<<m_prixNuit<<"€ par nuit.\n";
	cout<<"Il s'agit d'une chambre "<<this->getType()<<".\n";
}

bool Chambre::disponible(){ // à compléter
	return true; 
}