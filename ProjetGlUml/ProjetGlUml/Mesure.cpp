/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
double Mesure::GetValeur() const
// Algorithme :
//
{
	return valeur;
} //----- Fin de GetValeur

void Mesure::SetValeur(double valeur)
{
	this->valeur = valeur;
} //----- Fin de SetValeur

Date Mesure::GetDate() const
{
	return date;
}

void Mesure::SetDate(Date date)
{
	this->date = date;
}

string Mesure::GetIdAttribut() const
{
	return idAttribut;
}

void Mesure::SetIdAttribut(string idAttribut)
{
	this->idAttribut = idAttribut;
}

string Mesure::GetIdCapteur() const
{
	return idCapteur;
}

void Mesure::SetIdCapteur(string idCapteur)
{
	this->idCapteur = idCapteur;
}

//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & flux, Mesure & mesure)
// Algorithme :
//
{
	string tmp;

	int annee, mois, jour, heure, min, sec;
	getline(flux, tmp, '-');
	annee = atoi(tmp.c_str());
	getline(flux, tmp, '-');
	mois = atoi(tmp.c_str());
	getline(flux, tmp, 'T');
	jour = atoi(tmp.c_str());
	getline(flux, tmp, ':');
	heure = atoi(tmp.c_str());
	getline(flux, tmp, ':');
	min = atoi(tmp.c_str());
	getline(flux, tmp, ';');
	sec = atoi(tmp.c_str());
	Date date = Date(annee, mois, jour, heure, min, sec);
	mesure.SetDate(date);
	getline(flux, tmp, ';');
	mesure.SetIdCapteur(tmp);
	getline(flux, tmp, ';');
	mesure.SetIdAttribut(tmp);
	getline(flux, tmp);
	mesure.SetValeur(atof(tmp.c_str()));

	return flux;
} //----- Fin de operator >>

ostream& operator << (ostream& flux, Mesure& mesure)
// Algorithme :
{
	flux << mesure.GetIdAttribut() << " " << mesure.GetValeur() << endl;
	return flux;
}


//-------------------------------------------- Constructeurs - destructeur
//Mesure::Mesure ( const Mesure & unMesure )
// Algorithme :
//
/*{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Mesure>" << endl;
	#endif
}*/ //----- Fin de Mesure (constructeur de copie)


Mesure::Mesure()
	:valeur(0.0)
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut de <Mesure>" << endl;
	#endif
} //----- Fin de Mesure (constructeur par défaut)

Mesure::Mesure(double valeur, Date date, string attribut)
	:valeur(valeur), date(date), idAttribut(attribut)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Mesure>" << endl;
	#endif
} //----- Fin de Mesure


Mesure::~Mesure()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au destructeur de <Mesure>" << endl;
	#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

