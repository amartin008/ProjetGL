/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) Atmospher'IF par la Mims Team
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Capteur::GetId() const
// Algorithme :
//
{
	return this->id;
} //----- Fin de GetId

void Capteur::SetId(string id)
{
	this->id = id;
} //----- Fin de SetId

string Capteur::GetDescription() const
{
	return this->description;
} //----- Fin de GetDescription

void Capteur::SetDescription(string description)
{
	this->description = description;
} //----- Fin de SetDescription

Point Capteur::GetLocalisation() const {
	return localisation;
}

void Capteur::SetLocalisation(Point& p) {
	this->localisation = p;
}

//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & flux, Capteur & capteur)
// Algorithme :
//
{
	string tmp;
	double lat, lng;

	getline(flux, tmp, ';');
	capteur.SetId(tmp);
	getline(flux, tmp, ';');
	lat = atof(tmp.c_str());
	getline(flux, tmp, ';');
	lng = atof(tmp.c_str());
	capteur.SetLocalisation(*new Point(lat, lng));
	getline(flux, tmp);
	capteur.SetDescription(tmp);

	return flux;
} //----- Fin de operator >>

ostream & operator << (ostream & out, const Capteur & capteur)
// Algorithme :
//
{
	out << capteur.id << " " << capteur.description << endl;
	return out;
} //----- Fin de operator >>

bool operator < (const Capteur & c1, const Capteur & c2)
{
	if (c1.GetId().compare(c2.GetId()) < 0) {
		return true;
	} else {
		return false;
	}
}

//-------------------------------------------- Constructeurs - destructeur
//Capteur::Capteur ( const Capteur & unCapteur )
// Algorithme :
//
/*{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Capteur>" << endl;
	#endif
}*/ //----- Fin de Capteur (constructeur de copie)


Capteur::Capteur()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut de <Capteur>" << endl;
	#endif
} //----- Fin de Capteur (constructeur par défaut)

Capteur::Capteur(string id, string description, Point p)
	:id(id), description(description), localisation(p)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Capteur>" << endl;
	#endif
} //----- Fin de Capteur


Capteur::~Capteur()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au destructeur de <Capteur>" << endl;
	#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

