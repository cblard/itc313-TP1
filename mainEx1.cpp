/** 
  * Fichier:  mainEx1.cpp 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Fichier main utilisé pour la partie 1 du TP
  */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

using namespace std;

int main(){

	// test des dates

	Date date1(1,1,1);
	Date date2(1,1,1);
	date1.modifierDate(7,7,7);
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
	chambre1.modifierChambre(200);
	float prix=chambre1.getPrixNuit();
	cout<<"Le prix de la chambre est de "<<setprecision(2)<<fixed<<prix<<"€ par nuit.\n";
	cout<<"Il s'agit d'une chambre "<<chambre1.getType()<<".\n";
	Chambre chambre2(Double, 250);

	// test des hôtels

	Hotel hotel1("Hôtel", "Dijon");
	vector<Chambre> chambres = {chambre1,chambre2};
	hotel1.assignerChambres(chambres);
	cout<<"L'hôtel "<<hotel1.getNom()<<" se trouve à "<<hotel1.getVille()<<".\n";

	// test des réservations

	Reservation reservation1(date2, date1, hotel1, chambre1, client1);
	//reservation1.modifierDates(date2, date1);
	reservation1.changerChambre(0);
	cout<<"Le prix de la réservation est de : "<<reservation1.calculerPrix(chambre1)<<" euros.\n";

	return 0;
}