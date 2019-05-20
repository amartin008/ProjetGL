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

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Date.h"
#include "Attribut.h"
#include "Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    double GetValeur();
    
    void SetValeur(double valeur);

	Date GetDate();

	void SetDate(Date date);

	string GetIdAttribut();

	void SetIdAttribut(string idAttribut);

	string GetIdCapteur();

	void SetIdCapteur(string idCapteur);

//------------------------------------------------- Surcharge d'opérateurs
	friend std::istream & operator >> (std::istream & flux, Mesure & mesure);


//-------------------------------------------- Constructeurs - destructeur
    //Mesure ( const Mesure & unMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Mesure();
    
    Mesure(double valeur, Date date, string attributID);

    virtual ~Mesure();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégée

//----------------------------------------------------- Attributs protégés
	double valeur;
	Date date;
	std::string idAttribut;
	std::string idCapteur;
};

//-------------------------------- Autres définitions dépendantes de <Mesure>

#endif // MESURE_H

