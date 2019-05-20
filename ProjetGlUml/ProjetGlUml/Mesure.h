/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Date.h"
#include "Attribut.h"

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
};
#endif // MESURE_H

