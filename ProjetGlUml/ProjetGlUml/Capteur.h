/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) Atmospher'IF par la Mims Team
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) --------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "fstream"

using namespace std;

#include "Mesure.h"
#include "Point.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
// Cette classe permet de définir un objet Capteur avec toutes les informations 
//utiles sur celui-ci (types de mesure effectuées, position, etc.)
//
//------------------------------------------------------------------------

class Capteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string GetId() const;
    
    void SetId(std::string id);
    
    string GetDescription() const;
    
    void SetDescription(std::string description);

	Point GetLocalisation() const;

//------------------------------------------------- Surcharge d'opérateurs
	friend std::istream & operator >> (std::istream & flux, Capteur & capteur);

	friend std::ostream & operator << (std::ostream & out, Capteur & capteur);
//-------------------------------------------- Constructeurs - destructeur
    Capteur();
	//Mode d'emploi :
	//Constructeur par défaut 
    
    Capteur(string id, string description, Point local);
	//Mode d'emploi :
	//Constructeur de la classe Capteur

    virtual ~Capteur();
	//Mode d'emploi :
	//Destructeur de la classe Capteur
//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
	string id;
	string description;
	Point localisation;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H

