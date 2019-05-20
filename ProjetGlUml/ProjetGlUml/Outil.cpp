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
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Outil.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Outil::lancerOutil() {
	int choix = 0;
	int confirmation = 0;
	do {
		cout << "Bienvenue ! Que voulez-vous faire ?" << endl;
		cout << "1. Lancer le mode analyse" << endl;
		cout << "2. Lancer le mode surveillance" << endl;
		cout << "3. Quitter l'application" << endl;
		cout << "Votre choix : ";
		cin >> choix;
		cout << endl;
		if (cin.good()) {
			switch(choix) {
				case 1:
					cout << "Mode analyse" << endl;
					cout << endl;
					break;
				case 2:
					cout << "Mode surveillance" << endl;
					cout << endl;
					break;
				case 3:
					do {
						cout << "Etes-vous sur de vouloir quitter l'application ?" << endl;
						cout << "1. Oui" << endl;
						cout << "2. Non" << endl;
						cout << "Votre choix : ";
						cin >> confirmation;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							confirmation = 0;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						} else if (confirmation != 1 && confirmation != 2) {
							cout << "Veuillez selectionner un chiffre entre 1 et 2." << endl;
							cout << endl;
						}
					} while (confirmation!=1 && confirmation!=2);
					break;
				default:
					cout << "Veuillez selectionner un chiffre entre 1 et 3." << endl;
					cout << endl;
					break;
			}
		} else {
			cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (confirmation != 1);
}

string Outil::GetFichierCapteurs()
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

Capteur * Outil::verifierDonneesCapteurs(Contexte * contexte)
{
	return nullptr;
}

set<string> * Outil::verifierCapteurs(Contexte * contexte)
{
	set<string> capteursFonctionnels;
	set<string> * capteursDefectueux = new set<string>();


	return nullptr;
}


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

Outil::Outil(string fichierCapteurs, string fichierMesures, string fichierAttributs)
	:fichierCapteurs(fichierCapteurs), fichierMesures(fichierMesures), fichierAttributs(fichierAttributs)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Outil>" << endl;
	#endif
	ifstream fluxCapteurs(fichierCapteurs.c_str());
	string tmp;
	getline(fluxCapteurs, tmp);
	Capteur capteur;
	while (fluxCapteurs >> capteur) {
		listeCapteurs.push_back(capteur);
	}

	ifstream fluxAttributs(fichierAttributs.c_str());
	getline(fluxAttributs, tmp);
	Attribut attribut;
	while (fluxAttributs >> attribut) {
		listeAttributs.push_back(attribut);
	}

	//compléter les map et multimap...
}

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

