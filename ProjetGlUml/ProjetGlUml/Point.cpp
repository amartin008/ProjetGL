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

double Point::GetLatitude() const
{
	return latitude;
}

void Point::SetLatitude(double lat)
{
	latitude = lat;
}

double Point::GetLongitude() const
{
	return longitude;
}

void Point::SetLongitude(double lng)
{
	longitude = lng;
}

double Point::GetDistance(Point p) {
	return sqrt(pow(latitude - p.GetLatitude(),2) + pow(longitude - p.GetLongitude(),2));
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

Point::Point()
	:latitude(0), longitude(0)
{
#ifdef MAP
	cout << "Appel au constructeur par d�faut de <Point>" << endl;
#endif
} //----- Fin de Point


Point::Point(double lat, double longi)
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

