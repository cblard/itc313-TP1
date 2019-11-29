/** 
  * Fichier:  hotel.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe hotel
  */

#include "hotel.h"

Hotel::Hotel(string nom, string ville) : m_nom(nom), m_ville(ville) {
	m_id=0;
}

int Hotel::getID(){
	return m_id;
}

string Hotel::getNom(){
	return m_nom;
}

string Hotel::getVille(){
	return m_ville;
}

void Hotel::assignerChambres(vector <Chambre> chambres){
	for(unsigned long i=0; i<chambres.size(); i++){
		m_chambres.push_back(chambres.at(i));
	}
}
