/*************************************************************************
						   Point  -  description
							 -------------------
	d�but                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Point> (fichier Point.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

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


//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

Point::Point()
{
#ifdef MAP
	cout << "Appel au constructeur par d�faut de <Point>" << endl;
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

//----------------------------------------------------- M�thodes prot�g�es

