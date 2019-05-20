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

bool Contexte::EstDedans(Point p) 
{
	double dist = sqrt(pow(p.GetLatitude() - centre.GetLatitude(), 2) + pow(p.GetLongitude() - centre.GetLongitude(), 2));
	return (rayon >= dist);
}

bool Contexte::EstDedans(Date d)
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

float Contexte::GetRayon()
{
	return rayon;
}

Point Contexte::GetPoint()
{
	return centre;
}

Date Contexte::GetDebut()
{
	return debut;
}

Date Contexte::GetFin()
{
	return fin;
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
{
#ifdef MAP
	cout << "Appel au constructeur par défaut de <Contexte>" << endl;
#endif
} //----- Fin de Contexte (constructeur par défaut)

Contexte::Contexte(float rayon, Point centre, Date debut, Date fin)
	:rayon(rayon), centre(centre), debut(debut), fin(fin)
{
#ifdef MAP
	cout << "Appel au constructeur de <Contexte>" << endl;
#endif
} //----- Fin de Contexte


Contexte::~Contexte() 
{
#ifdef MAP
	cout << "Appel au destructeur de <Contexte>" << endl;
#endif
} //----- Fin de ~Contexte


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

