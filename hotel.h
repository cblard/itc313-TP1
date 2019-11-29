/** 
  * Fichier:  hotel.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Déclaration de la classe hotel
  */

#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include "chambre.h"
using namespace std;

class Hotel{
public:
	Hotel(string nom, string ville);
	int getID();
	string getNom();
	string getVille();
	void afficherInfos(); 
	void assignerChambres(vector <Chambre> chambres);
private:
	int m_id;
	string m_nom;
	string m_ville;
	vector <Chambre> m_chambres={};
};

#endif