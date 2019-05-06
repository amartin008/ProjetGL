/*************************************************************************
						   Contexte  -  description
							 -------------------
	d�but                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Contexte> (fichier Contexte.h) ----------------
#if ! defined ( CONTEXTE_H )
#define CONTEXTE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Date.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Contexte>
//
//
//------------------------------------------------------------------------

class Contexte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	bool EstDedans(Point p);

	bool EstDedans(Date d);

	float GetRayon();

	Point GetPoint();

	Date GetDebut();

	Date GetFin();

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�e

	//----------------------------------------------------- Attributs prot�g�s
	float rayon;
	Point centre;
	
	Date debut;
	Date fin;
};

//-------------------------------- Autres d�finitions d�pendantes de <Contexte>

#endif // CONTEXTE_H