/** 
  * Fichier:  client.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe Client
  */

#include "client.h"
#include <string>
using namespace std; 

Client::Client(string nom, string prenom) : m_nom(nom), m_prenom(prenom){
	m_id=0;
	m_nbReserv=0; 
}

int Client::getID(){
	return m_id;
}

string Client::getNom(){
	return m_nom; 
}

string Client::getPrenom(){
	return m_prenom;
}
	
int Client::getNbReserv(){
	return m_nbReserv;
}

void Client::ajouterReserv(){
	m_nbReserv++;
}

void Client::changerNom(string nom){
	m_nom=nom; 
}