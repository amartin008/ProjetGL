/*************************************************************************
						   Point  -  description
							 -------------------
	d�but                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ----------------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Point>
//
//
//------------------------------------------------------------------------

class Point
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	float GetLatitude();

	void SetLatitude(float lat);

	float GetLongitude();

	void SetLongitude(float lng);

	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur
	
	Point();

	Point(float latitude, float longitude);

	~Point();

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	float latitude;
	float longitude;
};

//-------------------------------- Autres d�finitions d�pendantes de <Point>

#endif // POINT_H


