/*************************************************************************
                           Contexte - description
                             -------------------
    début                : 06/05/2019
    copyright            : (C) Atmospher'IF par La Mims Team
*************************************************************************/

//---------- Interface de la classe <Contexte> (fichier Contexte.h) ----------------
#if ! defined ( CONTEXTE_H )
#define CONTEXTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Contexte>
//L’objet <Contexte> permet de rassembler les contextes géographique et temporel. 
//Les attributs Point et Rayon permettent de définir la zone géographique.
//Pour la période de vérification, l’objet <Contexte> prend un ou deux objets 
//<Date> suivant le choix d’une analyse à un moment donné ou sur une période.
//
//------------------------------------------------------------------------

class Contexte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	bool EstDedans(double latitude, double longitude) const; 

	bool EstDedans(Point p) const;

	bool EstDedans(const Date d) const;

	double GetRayon() const;

	void SetRayon(double rayon);

	Point GetPoint() const;
	
	void SetPoint(Point &unPoint);

	Date GetDebut() const;

	void SetDateDebut(Date &uneDateDebut);

	Date GetFin() const;

	void SetDateFin(Date &uneDateFin);

	//-------------------------------------------- Constructeurs - destructeur

	Contexte();
	//Mode d'emploi : 
	//Constructeur par défaut de la classe Contexte

	Contexte(double r, Point c);
	//Mode d'emploi :
	//Constructeur de la classe contexte permettant de définir un contexte
	//géographique

	Contexte(Date d, Date f = Date());
	//Mode d'emploi :
	//Constructeur de la classe contexte permettant de définir un contexte
	//temporel. La date de fin est optionnelle.

	virtual ~Contexte();
	//Mode d'emploi :
	//Destructeur de la classe Contexte.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés
	double rayon;
	Point centre;
	
	Date debut;
	Date fin;
};

//-------------------------------- Autres définitions dépendantes de <Contexte>

#endif // CONTEXTE_H
