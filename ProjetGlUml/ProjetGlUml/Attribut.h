/*************************************************************************
						   Attribut  -  description
							 -------------------
	début                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	std::string GetId();

	std::string GetUnit();

	std::string GetDescription();

	//------------------------------------------------- Surcharge d'opérateurs
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
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	std::string Id;
	std::string unit;
	std::string description;
};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // ATTRIBUT_H
