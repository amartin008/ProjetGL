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
	float GetLatitude() const;
	void SetLatitude(float lat);
	float GetLongitude() const;
	void SetLongitude(float lng);

	//-------------------------------------------- Constructeurs - destructeurs
	Point();
	//Mode d'emploi :
	//Constructeur par défaut de la classe Point

	Point(float latitude, float longitude);
	//Mode d'emploi :
	//Constructuer de la classe Point. Initialise la latitude et la longitude
	// caractérisant les coordonnées géographiques d'un point.
	
	~Point();
	//Mode d'emploi :
	//Destructeur par défaut de la classe Point

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs protégés
	float latitude;
	float longitude;
};
#endif // POINT_H


