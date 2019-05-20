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

//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & flux, Capteur & capteur)
// Algorithme :
//
{
	string tmp;

	getline(flux, tmp, ';');
	capteur.SetId(tmp);
	getline(flux, tmp, ';');
	capteur.GetLocalisation().SetLatitude((float)atof(tmp.c_str()));
	getline(flux, tmp, ';');
	capteur.GetLocalisation().SetLongitude((float)atof(tmp.c_str()));
	getline(flux, tmp);
	capteur.SetDescription(tmp);

	return flux;
} //----- Fin de operator >>

ostream & operator << (ostream & out, Capteur & capteur)
// Algorithme :
//
{
	out << capteur.id << " " << capteur.description << endl;
	return out;
} //----- Fin de operator >>


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

