/** 
  * Fichier:  main.cpp 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Novembre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Fichier main utilisé pour tester les différentes classes créées
  */

#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

using namespace std;
bool comparerDates(Date date1, Date date2);

int main(){
	// Question 6 : création d'un hôtel et de clients 

	vector <Chambre> chambre;
	Chambre chambreSingle(Single, 100);
	Chambre chambreDouble(Double, 125);
	Chambre chambreSuite(Suite, 210);
	chambreSingle.afficherInfos();

	for(int i=0;i<3;i++) {chambre.push_back(chambreSingle);}
	for(int i=3;i<8;i++) {chambre.push_back(chambreDouble);}
	for(int i=8;i<10;i++) {chambre.push_back(chambreSuite);}

	Hotel hotel("L'Hôtel", "Dijon");
	hotel.assignerChambres(chambre);

	// hotel.afficherInfos();

	vector <Client> clients; 

	Client client1("Johnny", "Depp"); clients.push_back(client1);
	Client client2("Johnny", "Hallyday"); clients.push_back(client2);
	Client client3("Johnny", "Bravo"); clients.push_back(client3);
	Client client4("Johnny", "Cash"); clients.push_back(client4);

	// for(int i=0;i<4;i++) {clients.at(i).afficherInfos();}

	int jour, mois, annee;
	bool checkInf=false; int compteur1=0;
	Date dateDebut, dateFin; 

	while(checkInf==false){
		if(compteur1!=0) {cout<<"La date de début est postérieure à la date de fin, réessayez.\n";}
		bool checkDate=false; int compteur2=0;
		while(checkDate==false){
			if(compteur2!=0) {cout<<"Erreur, réessayez.\n";}
			cout<<"Veuillez entrer la date de début de la réservation : \nEntrez le jour : "; cin>>jour;
			cout<<"Entrez le mois : "; cin>>mois;
			cout<<"Entrez l'année : "; cin>>annee;
			dateDebut.modifierDate(jour, mois, annee);
			checkDate=dateDebut.checkDate();
			compteur2++;
		}
		checkDate=false; compteur2=0;
		while(checkDate==false){
			if(compteur2!=0) {cout<<"Erreur, réessayez.\n";}
			cout<<"Veuillez entrer la date de fin de la réservation : \nEntrez le jour : "; cin>>jour;
			cout<<"Entrez le mois : "; cin>>mois;
			cout<<"Entrez l'année : "; cin>>annee;
			dateFin.modifierDate(jour, mois, annee);
			checkDate=dateFin.checkDate();
			compteur2++;
		}

		checkInf=comparerDates(dateDebut, dateFin);
		compteur1++;
	}
	Reservation reservation(dateDebut, dateFin, hotel, chambre.at(1), client1);
	cout<<reservation.calculerPrix(chambreSingle);


	return 0;
}

bool comparerDates(Date date1, Date date2){
	if(date1.getAnnee()>date2.getAnnee()){
		return false; 
	}
	if(date1.getAnnee()<date2.getAnnee()){
		return true; 
	}
	if(date1.getAnnee()==date2.getAnnee()){
		if(date1.getMois()>date2.getMois()){
			return false;
		}
		if(date1.getMois()<date2.getMois()){
			return true;
		}
		if(date1.getMois()==date2.getMois()){
			if(date1.getJour()>=date2.getJour()){
				return false; 
			}
			if(date1.getJour()<date2.getJour()){
				return true; 
			}

		}
	}
}