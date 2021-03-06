/*************************************************************************
                           Mesure - description
                             -------------------
    début                : 06/05/2019
    copyright            : (C) Atmospher'IF par La Mims Team
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
#include <string>
#include "Date.h"
#include "Attribut.h"
#include "Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
// La classe <Mesure> permet de stocker une ligne du fichier contenant les
// mesures effectuées par les capteurs et ainsi de stocker la valeur de la
// mesure.
//------------------------------------------------------------------------

class Mesure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    double GetValeur() const;

    void SetValeur(double valeur);

	Date GetDate() const;

	void SetDate(Date date);

	string GetIdAttribut() const;

	void SetIdAttribut(string idAttribut);

	string GetIdCapteur() const;

	void SetIdCapteur(string idCapteur);

//------------------------------------------------- Surcharge d'opérateurs
	friend std::istream & operator >> (std::istream & flux, Mesure & mesure);

	friend std::ostream& operator << (std::ostream& flux, Mesure& mesure);

//-------------------------------------------- Constructeurs - destructeur
    Mesure();
	//Mode d'emploi : 
	//Constructeur par défaut de la classe Mesure

    Mesure(double valeur, Date date, string attributID);
	//Mode d'emploi : 
	//Constructeur de la classe Mesure, 

   	virtual ~Mesure();
	//Mode d'emploi : 
	//Destructeur par défaut de la classe Mesure

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
	double valeur;
	Date date;
	string idAttribut;
	string idCapteur;
};
#endif // MESURE_H

