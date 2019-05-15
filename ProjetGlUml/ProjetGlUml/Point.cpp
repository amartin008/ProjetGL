/*************************************************************************
						   Point  -  description
							 -------------------
	début                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

float Point::GetLatitude()
{
	return latitude;
}

void Point::SetLatitude(float lat)
{
	latitude = lat;
}

float Point::GetLongitude()
{
	return longitude;
}

void Point::SetLongitude(float lng)
{
	longitude = lng;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Point::Point()
{
#ifdef MAP
	cout << "Appel au constructeur par défaut de <Point>" << endl;
#endif
} //----- Fin de Point


Point::Point(float lat, float longi)
	:latitude(lat), longitude(longi)
{
#ifdef MAP
	cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point()
{
#ifdef MAP
	cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

