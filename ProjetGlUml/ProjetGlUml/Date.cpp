/*************************************************************************
                           Date  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Date::GetAnnee()
// Algorithme :
//
{
	return this->annee;
} //----- Fin de GetAnnee

void Date::SetAnnee(int annee)
{
	this->annee = annee;
} //----- Fin de SetAnnee

int Date::GetMois()
{
	return this->mois;
} //----- Fin de GetMois

void Date::SetMois(int mois)
{
	this->mois = mois;
} //----- Fin de SetMois

int Date::GetJour()
{
	return this->jour;
} //----- Fin de GetJour

void Date::SetJour(int jour)
{
	this->jour = jour;
} //----- Fin de SetJour

int Date::GetHeure()
{
	return this->heure;
} //----- Fin de GetHeure

void Date::SetHeure(int heure)
{
	this->heure = heure;
} //----- Fin de SetHeure

int Date::GetMin()
{
	return this->min;
} //----- Fin de GetMin

void Date::SetMin(int min)
{
	this->min = min;
} //----- Fin de SetMin

int Date::GetSec()
{
	return this->sec;
} //----- Fin de GetSec

void Date::SetSec(int sec)
{
	this->sec = sec;
} //----- Fin de SetSec



//------------------------------------------------- Surcharge d'opérateurs
//Date & Date::operator = ( const Date & unDate )
// Algorithme :
//
/*{
}*/ //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Date::Date ( const Date & unDate )
// Algorithme :
//
/*{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
}*/ //----- Fin de Date (constructeur de copie)


Date::Date (int annee, int mois, int jour, int heure, int min, int sec)
	:annee(annee), mois(mois), jour(jour), heure(heure), min(min), sec(sec)
{
	#ifdef MAP
	    cout << "Appel au constructeur de <Date>" << endl;
	#endif
} //----- Fin de Date


Date::~Date ( )
{
	#ifdef MAP
		cout << "Appel au destructeur de <Date>" << endl;
	#endif
	
} //----- Fin de ~Date

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées