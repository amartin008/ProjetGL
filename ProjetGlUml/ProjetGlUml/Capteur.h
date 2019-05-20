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

#include "Point.h"
#include "Mesure.h"
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

	vector<Mesure> GetMesures() const;

	void SetMesures(vector<Mesure> mes);

//------------------------------------------------- Surcharge d'opérateurs
	friend istream & operator >> (istream & flux, Capteur & capteur);

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
	vector<Mesure> mesures;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H

