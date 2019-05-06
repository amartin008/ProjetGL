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
// type Mesure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut de <Mesure>" << endl;
	#endif
} //----- Fin de Mesure (constructeur par défaut)

Mesure::Mesure(double valeur)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Mesure>" << endl;
	#endif
	this->valeur = valeur;
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

