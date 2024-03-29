/** 
  * Fichier:  date.h 
  * Auteur:   C. Blard (christopher_blard@etu.u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Déclaration de la classe Date
  */

 #ifndef DATE_H
 #define DATE_H

class Date {
public:
	Date(int jour=1, int mois=1, int annee=1);
	int getJour() const;
	int getMois() const;
	int getAnnee() const;
	void setJour(int jour);
	void setMois(int mois);
	void setAnnee(int annee);
	void modifierDate(int jour, int mois, int annee);
	bool checkDate();
private:
	int m_jour;
	int m_mois;
	int m_annee;
};

#endif 