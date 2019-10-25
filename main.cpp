/** 
  * Fichier:  main.cpp 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Fichier main utilisé pour tester les différentes classes créées
  */

#include <iostream>
#include <string>
#include "date.h"
#include "client.h"

using namespace std;

int main(){
	Date date1(1,1,1);
	date1.modifierDate(2,2,2);
	int mois=date1.getMois();
	cout<<"Mois : "<<mois<<"\n";
	Client client1("Hallyday", "Johnny");
	client1.ajouterReserv();
	client1.changerNom("Bravo");
	string nomClient=client1.getNom();
	cout<<"Le nom du client est : \""<<nomClient<<"\" et il a "<<client1.getNbReserv()<<" réservation(s).\n"; 
	return 0;
}