/*************************************************************************
						   Contexte  -  description
							 -------------------
	d�but                : $06/05/2019$
	copyright            : (C) Atmospher'IF par la Mims Team
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
//L�objet <Contexte> permet de rassembler les contextes g�ographique et temporel. 
//Les attributs Point et Rayon permettent de d�finir la zone g�ographique.
//Pour la p�riode de v�rification, l�objet <Contexte> prend un ou deux objets 
//<Date> suivant le choix d�une analyse � un moment donn� ou sur une p�riode.
//
//------------------------------------------------------------------------

class Contexte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	bool EstDedans(Point p) const;

	bool EstDedans(Date d) const;

	float GetRayon() const;

	void setRayon(float rayon);

	Point GetPoint() const;
	
	void setPoint(Point &unPoint);

	Date GetDebut() const;

	void setDateDebut(Date &uneDateDebut);

	Date GetFin() const;

	void setDateFin(Date &uneDateFin);

	//-------------------------------------------- Constructeurs - destructeur

	Contexte();
	//Mode d'emploi : 
	//Constructeur par d�faut de la classe Contexte

	Contexte(float r, Point c);
	//Mode d'emploi :
	//Constructeur de la classe contexte permettant de d�finir un contexte
	//g�ographique

	Contexte(Date d, Date f=0);
	//Mode d'emploi :
	//Constructeur de la classe contexte permettant de d�finir un contexte
	//temporel. La date de fin est optionnelle.

	virtual ~Contexte();
	//Mode d'emploi :
	//Destructeur de la classe Contexte.

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Attributs prot�g�s
	float rayon;
	Point centre;
	
	Date debut;
	Date fin;
};

//-------------------------------- Autres d�finitions d�pendantes de <Contexte>

#endif // CONTEXTE_H