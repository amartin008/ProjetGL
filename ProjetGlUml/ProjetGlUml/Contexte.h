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

	bool EstDedans(Point p) const;

	bool EstDedans(Date d) const;

	float GetRayon() const;

	void setRayon(float rayon);

	Point GetPoint() const;
	
	void setPoint(Point &unPoint);

	Date GetDebut() const;

	void setDateDebut(Date &uneDateDebut);

	Date GetFin() const;

	void setDateFin(Date &uneDateFin);

	//-------------------------------------------- Constructeurs - destructeur

	Contexte();
	//Mode d'emploi : 
	//Constructeur par défaut de la classe Contexte

	Contexte(float r, Point c);
	//Mode d'emploi :
	//Constructeur de la classe contexte permettant de définir un contexte
	//géographique

	Contexte(Date d, Date f=0);
	//Mode d'emploi :
	//Constructeur de la classe contexte permettant de définir un contexte
	//temporel. La date de fin est optionnelle.

	virtual ~Contexte();
	//Mode d'emploi :
	//Destructeur de la classe Contexte.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés
	float rayon;
	Point centre;
	
	Date debut;
	Date fin;
};

//-------------------------------- Autres définitions dépendantes de <Contexte>

#endif // CONTEXTE_H
