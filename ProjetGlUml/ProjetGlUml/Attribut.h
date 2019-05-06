/*************************************************************************
						   Attribut  -  description
							 -------------------
	d�but                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	std::string GetId();

	std::string GetUnit();

	std::string GetDescription();

	//------------------------------------------------- Surcharge d'op�rateurs
		//Attribut & operator = ( const Attribut & unAttribut );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//-------------------------------------------- Constructeurs - destructeur
		//Attribut ( const Attribut & unAttribut );
		// Mode d'emploi (constructeur de copie) :
		//
		// Contrat :
		//

	Attribut();

	Attribut(std::string Id, std::string unit, std::string description);

	virtual ~Attribut();

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	std::string Id;
	std::string unit;
	std::string description;
};

//-------------------------------- Autres d�finitions d�pendantes de <Attribut>

#endif // ATTRIBUT_H
