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
	int quitterAnalyse = 0;
	int quitterSurveillance = 0;
	int ok = 0;

	string input;
	FILE* buffer;

	Contexte * contexte;
	set<Capteur>* capteursDefectueux;

	Capteur capteur;
	Attribut attribut;

	do {
		cout << "Bienvenue ! Que voulez-vous faire ?" << endl;
		cout << "1. Lancer le mode analyse" << endl;
		cout << "2. Lancer le mode surveillance" << endl;
		cout << "3. Specifiez le nom des fichiers" << endl;
		cout << "4. Quitter l'application" << endl;
		cout << "Votre choix : ";
		cin >> choix;
		cout << endl;
		
		if (cin.good()) {
			switch(choix) {
				case 1:
					quitterAnalyse = 0;
					do {
						cout << "Mode analyse - Que voulez-vous faire ?" << endl;
						cout << "1. Calcul de la qualite de l'air" << endl;
						cout << "2. Recherche des comportements de capteurs similaires" << endl;
						cout << "3. Recherche des caracteristiques de l'air a un point donne" << endl;
						cout << "4. Quitter le mode analyse" << endl;
						cout << "Votre choix : ";
						cin >> choix;
						cout << endl;

						if (cin.good()) {
							switch (choix) {
								case 1:
									cout << "Calcul de la qualite de l'air" << endl;
									cout << endl;
									break;
								case 2:
									cout << "Recherche des comportements de capteurs similaires" << endl;
									cout << endl;
									break;
								case 3:
									cout << "Recherche des caracteristiques de l'air a un point donne" << endl;
									cout << endl;
									break;
								case 4:
									quitterAnalyse = 1;
									break;
								default :
									cout << "Veuillez selectionner un chiffre entre 1 et 4." << endl;
									cout << endl;
									break;
							}
						} else {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (quitterAnalyse != 1);
					break;
				case 2:
					cout << "Veuillez selectionner la periode souhaitee" << endl;
					ok = 0;
					int anneeDebut;
					do {
						cout << "[DEBUT] Annee : " << endl;
						cin >> anneeDebut;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int moisDebut;
					do {
						cout << "[DEBUT] Mois : " << endl;
						cin >> moisDebut;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int jourDebut;
					do {
						cout << "[DEBUT] Jour : " << endl;
						cin >> jourDebut;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int heureDebut;
					do {
						cout << "[DEBUT] Heure : " << endl;
						cin >> heureDebut;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int minDebut;
					do {
						cout << "[DEBUT] Minute : " << endl;
						cin >> minDebut;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int secDebut;
					do {
						cout << "[DEBUT] Seconde : " << endl;
						cin >> secDebut;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int anneeFin;
					do {
						cout << "[FIN] Annee : " << endl;
						cin >> anneeFin;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int moisFin;
					do {
						cout << "[FIN] Mois : " << endl;
						cin >> moisFin;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int jourFin;
					do {
						cout << "[FIN] Jour : " << endl;
						cin >> jourFin;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int heureFin;
					do {
						cout << "[FIN] Heure : " << endl;
						cin >> heureFin;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int minFin;
					do {
						cout << "[FIN] Minute : " << endl;
						cin >> minFin;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					ok = 0;
					int secFin;
					do {
						cout << "[FIN] Seconde : " << endl;
						cin >> secFin;
						cout << endl;
						if (!cin.good()) {
							cout << "Entree invalide ! Veuillez selectionner un chiffre." << endl;
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							ok = 1;
						}
					} while (ok != 1);
					contexte = new Contexte(Date(anneeDebut, moisDebut, jourDebut, heureDebut, minDebut, secDebut), Date(anneeFin, moisFin, jourFin, heureFin, minFin, secFin));

					quitterSurveillance = 0;
					do {
						cout << "Mode surveillance - Que voulez-vous faire ?" << endl;
						cout << "1. Verification fiabilite des donnees" << endl;
						cout << "2. Verification fonctionnement des capteurs" << endl;
						cout << "3. Quitter le mode surveillance" << endl;
						cout << "Votre choix : ";
						cin >> choix;
						cout << endl;

						if (cin.good()) {
							switch (choix) {
								case 1:
									cout << "Verification fiabilite des donnees" << endl;
									cout << endl;
									break;
								case 2:
									capteursDefectueux = verifierCapteurs(contexte);
									if (capteursDefectueux->empty()) {
										cout << "Aucun capteur n'est defectueux sur la periode choisie" << endl;
										cout << endl;
									} else {
										cout << "Ci-dessous la liste des capteurs defectueux : " << endl;
										for (set<Capteur>::const_iterator it = capteursDefectueux->cbegin(); it != capteursDefectueux->cend(); ++it) {
											cout << *it;
										}
										cout << endl;
									}
									delete capteursDefectueux;
									break;
								case 3:
									quitterSurveillance = 1;
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
					} while (quitterSurveillance != 1);
					delete contexte;
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
					cout << "Veuillez selectionner un chiffre entre 1 et 4." << endl;
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

	for (vector<Capteur>::const_iterator it = listeCapteurs.cbegin(); it != listeCapteurs.cend(); ++it)
	{
		if (capteursFonctionnels.find(it->GetId()) == capteursFonctionnels.end())
		{
			capteursDefectueux->insert(*it);
		}
	}

	return capteursDefectueux;
}
