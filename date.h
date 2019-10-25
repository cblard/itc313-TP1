/** 
  * Fichier:  date.h 
  * Auteur:   C. Blard (christopher.blard@u-bourgogne.fr)
  * Date:     Octobre 2019 
  * Cours:    TP1 C++ 
  * Résumé:   Déclaration de la classe Date
  */

 #ifndef DATE_H
 #define DATE_H

class Date{
public:
	Date(int jour, int mois, int annee);
	int getJour() const;
	int getMois() const;
	int getAnnee() const;
	void modifierDate(int jour, int mois, int annee);
private:
	int m_jour;
	int m_mois;
	int m_annee;
};

#endif 