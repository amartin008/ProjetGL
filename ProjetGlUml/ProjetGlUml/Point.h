/*************************************************************************
                           Point - description
                             -------------------
    début                : 06/05/2019
    copyright            : (C) Atmospher'IF par La Mims Team
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ----------------
#if ! defined ( POINT_H )
#define POINT_H
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Point>
// La classe Point permet de définir un point géographique à partir d'une
// latitude et d'une longitude.
//------------------------------------------------------------------------

class Point
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	double GetLatitude() const;

	void SetLatitude(double lat);

	double GetLongitude() const;

	void SetLongitude(double lng);

	double GetDistance(Point p);

	//-------------------------------------------- Constructeurs - destructeurs
	Point();
	//Mode d'emploi :
	//Constructeur par défaut de la classe Point

	Point(double latitude, double longitude);
	//Mode d'emploi :
	//Constructuer de la classe Point. Initialise la latitude et la longitude
	// caractérisant les coordonnées géographiques d'un point.
	
	~Point();
	//Mode d'emploi :
	//Destructeur par défaut de la classe Point

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés
	double latitude;
	double longitude;
};
#endif // POINT_H


