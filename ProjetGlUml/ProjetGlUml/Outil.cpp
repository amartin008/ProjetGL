/*************************************************************************
                           Outil  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Outil> (fichier Outil.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Outil.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Outil::GetFichierCapteurs()
// Algorithme :
//
{
	return this->fichierCapteurs;
} //----- Fin de GetFichierCapteurs

void Outil::SetFichierCapteurs(string fichierCapteurs)
{
	this->fichierCapteurs = fichierCapteurs;
} //----- Fin de SetFichierCapteurs

string Outil::GetFichierMesures()
{
	return this->fichierMesures;
} //----- Fin de GetFichierMesures

void Outil::SetFichierMesures(string fichierMesures)
{
	this->fichierMesures = fichierMesures;
} //----- Fin de SetFichierMesures

string Outil::GetFichierAttributs()
{
	return this->fichierAttributs;
} //----- Fin de GetFichierAttributs

void Outil::SetFichierAttributs(string fichierAttributs)
{
	this->fichierAttributs = fichierAttributs;
} //----- Fin de SetFichierAttributs


//------------------------------------------------- Surcharge d'opérateurs
//Outil & Outil::operator = ( const Outil & unOutil )
// Algorithme :
//
/*{
}*/ //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Outil::Outil ( const Outil & unOutil )
// Algorithme :
//
/*{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Outil>" << endl;
	#endif
}*/ //----- Fin de Outil (constructeur de copie)


Outil::Outil()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut de <Outil>" << endl;
	#endif
} //----- Fin de Outil (constructeur par défaut)


Outil::~Outil()
// Algorithme :
//
{
	#ifdef MAP
		cout << "Appel au destructeur de <Outil>" << endl;
	#endif
} //----- Fin de ~Outil


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

