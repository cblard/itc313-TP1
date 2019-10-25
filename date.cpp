/** 
  * Fichier:  date.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe Date
  */

 #include "date.h"

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
