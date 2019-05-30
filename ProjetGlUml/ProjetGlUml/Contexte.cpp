/*************************************************************************
						   Contexte  -  description
							 -------------------
	début                : $06/05/2019$
	copyright            : (C) Atmospher'IF par la Mims Team
*************************************************************************/

//---------- Réalisation de la classe <Contexte> (fichier Contexte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Contexte.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Contexte::EstDedans(Point p) const
{
	double dist = sqrt(pow(p.GetLatitude() - centre.GetLatitude(), 2) + pow(p.GetLongitude() - centre.GetLongitude(), 2));
	return (rayon >= dist);
}

bool Contexte::EstDedans(const Date d) const
{
	if (debut.GetAnnee() < d.GetAnnee() && fin.GetAnnee() > d.GetAnnee()) {
		return true;
	}
	else if (debut.GetAnnee() == d.GetAnnee() || fin.GetAnnee() == d.GetAnnee()) {
		if (debut.GetMois() < d.GetMois() && fin.GetMois() > d.GetMois()) {
			return true;
		}
		else if (debut.GetMois() == d.GetMois() || fin.GetMois() == d.GetMois()) {
			if (debut.GetJour() < d.GetJour() && fin.GetJour() > d.GetJour()) {
				return true;
			}
			else if (debut.GetJour() == d.GetJour() || fin.GetJour() == d.GetJour()) {
				if (debut.GetHeure() < d.GetHeure() && fin.GetHeure() > d.GetHeure()) {
					return true;
				}
				else if (debut.GetHeure() == d.GetHeure() && fin.GetHeure() == d.GetHeure()) {
					if (debut.GetMin() < d.GetMin() && fin.GetMin() > d.GetMin()) {
						return true;
					}
					else if (debut.GetMin() == d.GetMin() && fin.GetMin() == d.GetMin()) {
						if (debut.GetSec() < d.GetSec() && fin.GetSec() > d.GetSec()) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

float Contexte::GetRayon() const
{
	return rayon;
}

Point Contexte::GetPoint() const
{
	return centre;
}

Date Contexte::GetDebut() const
{
	return debut;
}

Date Contexte::GetFin() const
{
	return fin;
}

void Contexte::SetRayon(float rayon) {
	this->rayon = rayon;
}

void Contexte::SetPoint(Point &unPoint) {
	this->centre = unPoint;
}

void Contexte::SetDateDebut(Date &uneDateDebut) {
	this->debut = uneDateDebut;
}

void Contexte::SetDateFin(Date &uneDateFin) {
	this->fin = uneDateFin;
}


//-------------------------------------------- Constructeurs - destructeur
//Contexte::Contexte ( const Contexte & unContexte )
// Algorithme :
//
/*{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Contexte>" << endl;
	#endif
}*/ //----- Fin de Contexte (constructeur de copie)

Contexte::Contexte()
	:rayon(0.0)
{
#ifdef MAP
	cout << "Appel au constructeur par défaut de <Contexte>" << endl;
#endif
} //----- Fin de Contexte (constructeur par défaut)

Contexte::Contexte(float rayon, Point centre)
	:rayon(rayon), centre(centre)
{
#ifdef MAP
	cout << "Appel au constructeur de <Contexte>" << endl;
#endif
} //----- Fin de Contexte


Contexte::Contexte(Date debut, Date fin)
	:debut(debut), fin(fin), rayon(0.0)
{
#ifdef MAP
	cout << "Appel au constructeur de <Contexte>" << endl;
#endif
}

Contexte::~Contexte() 
{
#ifdef MAP
	cout << "Appel au destructeur de <Contexte>" << endl;
#endif
} //----- Fin de ~Contexte


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

