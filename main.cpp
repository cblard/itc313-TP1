/** 
  * Fichier:  main.cpp 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Fichier main utilisé pour tester les différentes classes créées
  */

#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"
#include "client.h"
#include "chambre.h"

using namespace std;

int main(){

	// test des dates

	Date date1(1,1,1);
	date1.modifierDate(2,2,2);
	int mois=date1.getMois();
	cout<<"Mois : "<<mois<<"\n";

	// test des clients 

	Client client1("Hallyday", "Johnny");
	client1.ajouterReserv();
	client1.changerNom("Bravo");
	string nomClient=client1.getNom();
	cout<<"Le nom du client est : \""<<nomClient<<"\" et il a "<<client1.getNbReserv()<<" réservation(s).\n";

	// test des chambres

	Chambre chambre1(Single, 180.50);
	chambre1.modifierChambre(200.50);
	float prix=chambre1.getPrixNuit();
	cout<<"Le prix de la chambre est de "<<setprecision(2)<<fixed<<prix<<"€ par nuit.\n";
	cout<<"Il s'agit d'une chambre "<<chambre1.getType()<<".\n";
	return 0;
}