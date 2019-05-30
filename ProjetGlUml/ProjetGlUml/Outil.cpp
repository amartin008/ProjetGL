#define _CRT_SECURE_NO_WARNINGS

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

using namespace std;

//------------------------------------------------------ Include personnel
#include "Outil.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Outil::lancerOutil() {
	int choix = 0;
	int confirmation = 0;

	string input;
	FILE* buffer;

	Capteur capteur;
	Attribut attribut;

	do {
		cout << "Bienvenue ! Que voulez-vous faire ?" << endl;
		cout << "1. Lancer le mode analyse" << endl;
		cout << "2. Lancer le mode surveillance" << endl;
		cout << "3. Specifiez l'emplacement des fichiers" << endl;
		cout << "4. Quitter l'application" << endl;
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
					cout << "Les fichiers doivent etre dans le repertoire data_folder" << endl;
					cout << endl;
					
					do{
						cout << "Fichier concernant les capteurs (N pour annuler): ";
						cin >> input;

						cout << endl;
						buffer = fopen(("data_folder/"+input).c_str(), "r");
						if (!input.compare("N")) {
							break;
						} else if(buffer == NULL){
							cerr << "Fichier inexistant" << endl;
							cout << endl;
						} else {
							SetFichierCapteurs("data_folder/" + input);
							ifstream flux(fichierCapteurs);
							getline(flux, input);
							while (flux >> capteur) {
								listeCapteurs.push_back(capteur);
							}
						}
					} while (buffer == NULL);
					
					if (buffer != NULL) {
						fclose(buffer);
					}					

					do {
						cout << "Fichier concernant les attributs (N pour annuler): ";
						cin >> input;

						cout << endl;
						buffer = fopen(("data_folder/" + input).c_str(), "r");

						if (!input.compare("N")) {
							break;
						} else if (buffer == NULL) {
							cerr << "Fichier inexistant" << endl;
							cout << endl;
						} else {
							SetFichierAttributs("data_folder/" + input);
							ifstream flux(fichierAttributs);
							getline(flux, input);
							while (flux >> attribut) {
								listeAttributs.push_back(attribut);
							}
						}
					} while (buffer == NULL);

					if (buffer != NULL) {
						fclose(buffer);
					}

					do{
						cout << "Fichier concernant les mesures (N pour annuler): ";
						cin >> input;

						cout << endl;
						buffer = fopen(("data_folder/" + input).c_str(), "r");
						if (!input.compare("N")) {
							break;
						} else if (buffer == NULL){
							cerr << "Fichier inexistant" << endl;
							cout << endl;
						} else {
							SetFichierMesures("data_folder/" + input);
						}
					} while (buffer == NULL);
					
					if (buffer != NULL) {
						fclose(buffer);
					}

					break;
				case 4:
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

string Outil::GetFichierCapteurs() const
{
	return this->fichierCapteurs;
} //----- Fin de GetFichierCapteurs

void Outil::SetFichierCapteurs(string fichierCapteurs)
{
	this->fichierCapteurs = fichierCapteurs;
} //----- Fin de SetFichierCapteurs


string Outil::GetFichierMesures() const

{
	return this->fichierMesures;
} //----- Fin de GetFichierMesures

void Outil::SetFichierMesures(string fichierMesures)
{
	this->fichierMesures = fichierMesures;
} //----- Fin de SetFichierMesures

string Outil::GetFichierAttributs() const
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
Capteur * Outil::verifierDonneesCapteurs(const Contexte * contexte)
{
	return nullptr;
}

set<Capteur> * Outil::verifierCapteurs(const Contexte * contexte)
{
	set<string> capteursFonctionnels;
	set<Capteur> * capteursDefectueux = new set<Capteur>();
	ifstream flux(fichierMesures);

	Mesure mesure;
	string tmp;
	getline(flux, tmp);
	while (flux >> mesure)
	{
		if (contexte->EstDedans(mesure.GetDate()))
		{
			capteursFonctionnels.insert(mesure.GetIdCapteur());
		}
	}
	
	/*
	for (vector<Capteur>::const_iterator it = listeCapteurs.cbegin(); it != listeCapteurs.cend(); it++)
	{
		if (capteursFonctionnels.find(it->GetId()) == capteursFonctionnels.end())
		{
			capteursDefectueux->insert(*it);
		}
	}
	
	for (auto e : listeCapteurs)
	{
		if (capteursFonctionnels.find(e.GetId()) ==  capteursFonctionnels.end())
		{
			capteursDefectueux->insert(e);
		}
	}*/

	return capteursDefectueux;
}
