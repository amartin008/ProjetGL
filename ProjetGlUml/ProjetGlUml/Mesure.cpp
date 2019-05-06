/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
double Mesure::GetValeur()
// Algorithme :
//
{
	return valeur;
} //----- Fin de GetValeur

void Mesure::SetValeur(double valeur)
{
	this->valeur = valeur;
} //----- Fin de SetValeur


//------------------------------------------------- Surcharge d'opérateurs
//Mesure & Mesure::operator = ( const Mesure & unMesure )
// Algorithme :
//
/*{
}*/ //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Mesure::Mesure ( const Mesure & unMesure )
// Algorithme :
//
/*{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Mesure>" << endl;
	#endif
}*/ //----- Fin de Mesure (constructeur de copie)


Mesure::Mesure()
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut de <Mesure>" << endl;
	#endif
} //----- Fin de Mesure (constructeur par défaut)

Mesure::Mesure(double valeur, Date date, string attribut)
	:valeur(valeur), date(date), attributID(attribut)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Mesure>" << endl;
	#endif
} //----- Fin de Mesure


Mesure::~Mesure()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au destructeur de <Mesure>" << endl;
	#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

