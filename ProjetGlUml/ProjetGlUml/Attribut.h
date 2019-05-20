/*************************************************************************
                           Attribut - description
                             -------------------
    début                : 06/05/2019
    copyright            : (C) Atmospher'IF par La Mims Team
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
// Un objet Attribut correspondant au type de gaz, c'est-à-dire à un type 
// de mesure effectuée par un capteur
//------------------------------------------------------------------------

class Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	string GetId() const;

	void SetId(string id);

	string GetUnit() const;

	void SetUnit(string unit);

	string GetDescription() const;

	void SetDescription(string description);

	//------------------------------------------------- Surcharge d'opérateurs
	friend istream & operator >> (istream & flux, Attribut & attribut);

	//-------------------------------------------- Constructeurs - destructeur
	
	Attribut();
	// Mode d'emploi :
	// Constructeur par défaut de la classe Attribut
	
	Attribut(string Id, string unit, string description);
	// Mode d'emploi :
	// Constructeur de la classe Attribut
	
	virtual ~Attribut();
	// Mode d'emploi :
	// Destructeur par défaut de la classe Attribut
	
//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés
	string id;
	string unit;
	string description;
};
#endif // ATTRIBUT_H
