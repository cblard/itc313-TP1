/** 
  * Fichier:  client.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Déclaration de la classe Client
  */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client{
public:
	Client(string nom, string prenom);
	int getID();
	string getNom();
	string getPrenom();
	int getNbReserv();
	void ajouterReserv();
	void changerNom(string nom);
	void afficherInfos(); 
private:
	int m_id;
	string m_nom;
	string m_prenom;
	int m_nbReserv; 
};

#endif