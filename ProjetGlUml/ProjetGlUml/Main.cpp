#define _CRT_SECURE_NO_WARNINGS

/*************************************************************************
						   Main  -  description
							 -------------------
	d�but                : $15/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;
#include <string>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Main.h"
#include "Outil.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions priv�es
//static type nom ( liste de param�tres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main() {
	Outil* outil = new Outil();
	outil->lancerOutil();

	return 0;
}

