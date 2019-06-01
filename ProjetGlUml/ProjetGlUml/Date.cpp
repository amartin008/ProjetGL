/*************************************************************************
                           Date  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) Atmospher'IF par la Mims Team

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
int Date::GetAnnee() const
// Algorithme :
//
{
	return this->annee;
} //----- Fin de GetAnnee

void Date::SetAnnee(int annee)
{
	this->annee = annee;
} //----- Fin de SetAnnee

int Date::GetMois() const
{
	return this->mois;
} //----- Fin de GetMois

void Date::SetMois(int mois)
{
	this->mois = mois;
} //----- Fin de SetMois

int Date::GetJour() const
{
	return this->jour;
} //----- Fin de GetJour

void Date::SetJour(int jour)
{
	this->jour = jour;
} //----- Fin de SetJour

int Date::GetHeure() const
{
	return this->heure;
} //----- Fin de GetHeure

void Date::SetHeure(int heure)
{
	this->heure = heure;
} //----- Fin de SetHeure

int Date::GetMin() const
{
	return this->min;
} //----- Fin de GetMin

void Date::SetMin(int min)
{
	this->min = min;
} //----- Fin de SetMin

int Date::GetSec() const
{
	return this->sec;
} //----- Fin de GetSec

void Date::SetSec(int sec)
{
	this->sec = sec;
} //----- Fin de SetSec



//------------------------------------------------- Surcharge d'opérateurs

bool operator <= (const Date & d1, const Date & d2)
{
	if (d1.annee < d2.annee) {
		return true;
	} else if (d1.annee == d2.annee) {
		if (d1.mois < d2.mois) {
			return true;
		} else if (d1.mois == d2.mois) {
			if (d1.jour < d2.jour) {
				return true;
			} else if (d1.jour == d2.jour) {
				if (d1.heure < d2.heure) {
					return true;
				} else if (d1.heure == d2.heure) {
					if (d1.min < d2.min) {
						return true;
					} else if (d1.min == d2.min) {
						if (d1.sec <= d2.sec) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


//-------------------------------------------- Constructeurs - destructeur


Date::Date()
{
	#ifdef MAP
	    cout << "Appel au constructeur par défaut de <Date>" << endl;
	#endif
} //----- Fin de Date (constructeur par défaut)

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
