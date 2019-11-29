/** 
  * Fichier:  reservation.cpp
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Novembre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Définition de la classe Réservation
  */

#include "reservation.h"
#include <iostream>

using namespace std; 

bool comparerDate(Date date1, Date date2);

Reservation::Reservation(Date debut, Date fin, Hotel hotel, Chambre chambre, Client client){ // Constructeur de Reservation 
	if(comparerDate(debut, fin)==true) {
		m_dateDebut=debut;
		m_dateFin=fin;
		m_hotelID=hotel.getID();
		m_chambreID=chambre.getID();
		m_clientID=client.getID();
	}
	else{
		cout<<"Impossible de créer une réservation, la date de la fin de réservation n'est pas correcte.";
	}
}

void Reservation::modifierDates(Date debut, Date fin){
	if(comparerDate(debut, fin)==true){m_dateDebut=debut; m_dateFin=fin;} // On compare les dates et on vérifie que date1<date2 avant de modifier la date 
	else{cout<<"Impossible de modifier la date.";}
}

int Reservation::calculerNbNuits(){
	vector <int> tab={31,28,31,30,31,30,31,31,30,31,30,31};
	int annee1=m_dateDebut.getAnnee(), annee2=m_dateFin.getAnnee();
	int mois1=m_dateDebut.getMois(), mois2=m_dateFin.getMois();
	int jour1=m_dateDebut.getJour(), jour2=m_dateFin.getJour();

	int nbAnnees=0;
	if(annee2!=annee1){nbAnnees=annee2-annee1;}
	int nbMois=0;
	if(mois1<mois2){nbMois=mois2-mois1;}
	if(mois1>=mois2){nbMois=12-mois1-1+mois2; nbAnnees--;}
	int nbJours=0;
	if(jour1<jour2){nbJours=jour2-jour1;}
	if(jour1>=jour2){nbJours=tab.at(mois1-1)-jour1+jour2; nbMois--;}
	return nbAnnees*365+nbMois*30+nbJours-1; // On élimine le cas des années bissextiles

}
float Reservation::calculerPrix(Chambre chambre){
	int nbNuits=this->calculerNbNuits(); // On appelle le calcul de nombre de nuits 
	m_prix=chambre.getPrixNuit()*nbNuits;
	if(nbNuits>=15) m_prix*=0.9;
	return m_prix;
}

void Reservation::changerChambre(int id){
	m_chambreID=id;
}


// Fonction pour vérifier que date1<date2 

bool comparerDate(Date date1, Date date2){ 
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