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
	cout<<"nb nuits : "<<reservation.calculerNbNuits();
	//cout<<"Le prix total de la réservation s'élève à : "<<reservation.calculerPrix(chambreSingle)<<" euros.\n";

	int choix=0; bool checkChambre=false; compteur1=0;
	while(checkChambre==false){
		if(compteur1!=0) {cout<<"Ce type de chambre n'est pas disponible, veuillez réessayer.";}
		while(choix!=1 && choix!=2 && choix!=3){
		cout<<"\nQuel type de chambre souhaitez-vous ?\n 1.Single\n 2.Double\n 3.Suite\nEntrez votre choix (1, 2 ou 3):";
		cin>>choix; 
		}
		Chambre chambreClient;
		chambreClient.modifierChambre(choix);
		chambreClient.afficherInfos();
		checkChambre=chambreClient.disponible();
		compteur1++;
	}
	/*string nom, prenom;
	cout<<"Entrez votre nom : "; cin>>nom; 
	cout<<"Entrez votre prénom : "; cin>>prenom;
	Client client(nom, prenom);*/
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
