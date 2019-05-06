/*************************************************************************
						   Contexte  -  description
							 -------------------
	début                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Contexte> (fichier Contexte.h) ----------------
#if ! defined ( CONTEXTE_H )
#define CONTEXTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Contexte>
//
//
//------------------------------------------------------------------------

class Contexte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	bool EstDedans(Point p);

	bool EstDedans(Date d);

	float GetRayon();

	Point GetPoint();

	Date GetDebut();

	Date GetFin();

	//------------------------------------------------- Surcharge d'opérateurs
		//Contexte & operator = ( const Contexte & unContexte );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//-------------------------------------------- Constructeurs - destructeur
		//Contexte ( const Contexte & unContexte );
		// Mode d'emploi (constructeur de copie) :
		//
		// Contrat :
		//

	Contexte();

	Contexte(float r, Point c, Date d, Date f);

	virtual ~Contexte();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégée

	//----------------------------------------------------- Attributs protégés
	float rayon;
	Point centre;
	
	Date debut;
	Date fin;
};

//-------------------------------- Autres définitions dépendantes de <Contexte>

#endif // CONTEXTE_H