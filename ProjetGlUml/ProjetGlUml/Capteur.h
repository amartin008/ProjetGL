/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Point.h"
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    std::string GetId();
    
    void SetId(std::string id);
    
    std::string GetDescription();
    
    void SetDescription(std::string description);

	Point GetLocalisation();

	std::vector<Mesure> GetMesures();

	void SetMesures(vector<Mesure> mes);
//------------------------------------------------- Surcharge d'opérateurs
    //Capteur & operator = ( const Capteur & unCapteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Capteur ( const Capteur & unCapteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Capteur();
    
    Capteur(std::string id, std::string description, Point local);

    virtual ~Capteur();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	std::string id;
	std::string description;
	Point localisation;
	std::vector<Mesure> mesures;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H

