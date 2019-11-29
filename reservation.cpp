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

Reservation::Reservation(Date debut, Date fin, Hotel hotel, Chambre chambre, Client client){
	if(debut.getMois()<fin.getMois()) { // On suppose que la réservation se passe sur la même année, la classe Date ne comprenant pas encore le système d'années
		m_dateDebut=debut;
		m_dateFin=fin;
		m_hotelID=hotel.getID();
		m_chambreID=chambre.getID();
		m_clientID=client.getID();
	}
	if(debut.getMois()==fin.getMois()){
			if(debut.getJour()<fin.getJour()){
				m_dateDebut=debut;
				m_dateFin=fin;
				m_hotelID=hotel.getID();
				m_chambreID=chambre.getID();
				m_clientID=client.getID();
			}
			else cout<<"Impossible de créer une réservation, la date de la fin de réservation n'est pas correcte.";
	}	
	if(debut.getMois()<fin.getMois()){
		cout<<"Impossible de créer une réservation, la date de la fin de réservation n'est pas correcte.";
	}
}

void Reservation::modifierDates(Date debut, Date fin){
	if(debut.getMois()<fin.getMois()) { // On suppose que la réservation se passe sur la même année, la classe Date ne comprenant pas encore le système d'années
		m_dateDebut=debut;
		m_dateFin=fin;
	}
	if(debut.getMois()==fin.getMois()){
			if(debut.getJour()<fin.getJour()){
				m_dateDebut=debut;
				m_dateFin=fin;
			}
			else cout<<"Impossible de modifier la réservation, la date de la fin de réservation n'est pas correcte.";
	}	
	if(debut.getMois()<fin.getMois()){
		cout<<"Impossible de modifier la réservation, la date de la fin de réservation n'est pas correcte.";
	}
}

float Reservation::calculerPrix(Chambre chambre){
	int nbMois=0;;
	if(m_dateDebut.getMois()!=m_dateFin.getMois()){
		nbMois=m_dateFin.getMois()-m_dateDebut.getMois()-1;
		cout<<nbMois;
	}
	int nbJours=(30-m_dateDebut.getJour())+m_dateFin.getJour();
	int nbNuits=nbMois*30+nbJours; 
	m_prix=chambre.getPrixNuit()*nbNuits;
	if(nbNuits>=15) m_prix*=0.9;
	return m_prix;
}

void Reservation::changerChambre(int id){
	m_chambreID=id;
}