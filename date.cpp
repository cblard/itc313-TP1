/** 
  * Fichier:  date.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe Date
  */

#include "date.h"
#include <iostream>

using namespace std; 

Date::Date(int jour, int mois, int annee) : m_jour(jour), m_mois(mois), m_annee(annee) {
}

int Date::getJour() const{
	return m_jour;
}

int Date::getMois() const{
	return m_mois;
}

int Date::getAnnee() const{
	return m_annee;
}

void Date::modifierDate(int jour, int mois, int annee){
	m_jour=jour;
	m_mois=mois;
	m_annee=annee;
}

// Fonction qui vérifie si une date existe bien

bool Date::checkDate(){ 
	switch(m_mois){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
		if(m_jour>0 && m_jour<=31) {return true;} else {return false;}
		break;

		case 2:
		if(m_jour>0 && m_jour<=28) {return true;} else {return false;}
		break;

		case 4: case 6: case 9: case 11: 
		if(m_jour>0 && m_jour<=30) {return true;} else {return false;}
	}
}
