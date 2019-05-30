/*************************************************************************
						   Attribut  -  description
							 -------------------
	début                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Attribut::GetId() const {
	return id;
}

void Attribut::SetId(string id) {
	this->id = id;
}

string Attribut::GetUnit() const {
	return unit;
}

void Attribut::SetUnit(string unit) {
	this->unit = unit;
}

string Attribut::GetDescription() const {
	return description;
}

void Attribut::SetDescription(string description) {
	this->description = description;
}

//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & flux, Attribut & attribut)
// Algorithme :
//
{
	string tmp;

	getline(flux, tmp, ';');
	attribut.SetId(tmp);
	getline(flux, tmp, ';');
	attribut.SetUnit(tmp);
	getline(flux, tmp, ';');
	attribut.SetDescription(tmp);
	getline(flux, tmp);

	return flux;
} //----- Fin de operator >>

//-------------------------------------------- Constructeurs - destructeur

Attribut::Attribut()
{
#ifdef MAP
	cout << "Appel au constructeur par défaut de <Attribut>" << endl;
#endif
} //----- Fin de Attribut

Attribut::Attribut(string id, string unit, string description)
	:id(id), unit(unit), description(description)
{
#ifdef MAP
	cout << "Appel au constructeur de <Attribut>" << endl;
#endif
} //----- Fin de Attribut


Attribut::~Attribut()
{
#ifdef MAP
	cout << "Appel au destructeur de <Attribut>" << endl;
#endif
} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées