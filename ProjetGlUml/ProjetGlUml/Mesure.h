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

//------------------------------------------------- Surcharge d'opérateurs
    //Mesure & operator = ( const Mesure & unMesure );
    // Mode d'emploi :
    //
    // Contrat :
    //


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
	std::string attributID;
};

//-------------------------------- Autres définitions dépendantes de <Mesure>

#endif // MESURE_H

