/*************************************************************************
						   Attribut  -  description
							 -------------------
	d�but                : $06/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/
//---------- R�alisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

string Attribut::GetId() {
	return Id;
}

string Attribut::GetUnit() {
	return unit;
}

string Attribut::GetDescription() {
	return description;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

Attribut::Attribut()
{
#ifdef MAP
	cout << "Appel au constructeur par d�faut de <Attribut>" << endl;
#endif
} //----- Fin de Attribut

Attribut::Attribut(string Id, string unit, string description)
	:Id(Id), unit(unit), description(description)
{
#ifdef MAP
	cout << "Appel au constructeur de <Attribut>" << endl;
#endif
} //----- Fin de Attribut


Attribut::~Attribut()
{
#ifdef MAP
	cout << "Appel au destructeur de <Attribut>" << endl;
#endif
} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es