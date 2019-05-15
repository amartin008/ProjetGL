#define _CRT_SECURE_NO_WARNINGS

/*************************************************************************
						   Main  -  description
							 -------------------
	début                : $15/05/2019$
	copyright            : (C) $2019$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Main.h"
#include "Outil.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
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
	string fichierCapteurs;
	string fichierMesures;
	string fichierAttributs;

	cout << "Avant de lancer l'application, veuillez saisir les emplacements des differents fichiers ci-dessous : " << endl;
	cout << "Exemple (fichier dans le meme dossier que le code) : nomDuFichier.csv" << endl;
	cout << "Exemple (fichier dans un dossier different) : C/Temp/nomDuFichier.csv ou ../Temp/nomDuFichier.csv" << endl;
	cout << endl;

	int ok = 0;
	while (ok != 1)
	{
		cout << "Fichier concernant les capteurs : ";
		cin >> fichierCapteurs;
		cout << endl;
		FILE * ficCapteurs = fopen(fichierCapteurs.c_str(), "r");
		if (ficCapteurs == NULL)
		{
			cerr << "Fichier inexistant" << endl;
			cout << endl;
		}
		else
		{
			fclose(ficCapteurs);
			ok = 1;
		}
	}
	ok = 0;
	while (ok != 1)
	{
		cout << "Fichier concernant les mesures : ";
		cin >> fichierMesures;
		cout << endl;
		FILE * ficMesures = fopen(fichierMesures.c_str(), "r");
		if (ficMesures == NULL)
		{
			cerr << "Fichier inexistant" << endl;
			cout << endl;
		}
		else
		{
			fclose(ficMesures);
			ok = 1;
		}
	}
	ok = 0;
	while (ok != 1)
	{
		cout << "Fichier concernant les attributs : ";
		cin >> fichierAttributs;
		cout << endl;
		FILE * ficAttributs = fopen(fichierAttributs.c_str(), "r");
		if (ficAttributs == NULL)
		{
			cerr << "Fichier inexistant" << endl;
			cout << endl;
		}
		else
		{
			fclose(ficAttributs);
			ok = 1;
		}
	}
	
	Outil* outil = new Outil(fichierCapteurs, fichierMesures, fichierAttributs);
	outil->lancerOutil();

	return 0;
}

