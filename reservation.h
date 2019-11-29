/** 
  * Fichier:  reservation.h
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Novembre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Déclaration de la classe Réservation
  */

#ifndef RESERVATION_H
#define RESERVATION_H

#include "date.h"
#include "hotel.h"
#include "chambre.h"
#include "client.h"

class Reservation {
private:
	int m_id;
	Date m_dateDebut;
	Date m_dateFin;
	int m_hotelID;
	int m_chambreID;
	int m_clientID;
	float m_prix;
public:
	Reservation(Date debut, Date fin, Hotel hotel, Chambre chambre, Client client);
	void modifierDates(Date debut, Date fin);
	void changerChambre(int id);
	int calculerNbNuits();
	float calculerPrix(Chambre chambre);
};

#endif