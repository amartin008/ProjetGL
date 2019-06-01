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

	string input;
	FILE* buffer;

	Contexte * contexte;
	set<Capteur>* capteursDefectueux;

	Capteur capteur;
	Attribut attribut;
	Mesure mesure;

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
					int anneeDebut, moisDebut, jourDebut, heureDebut, minDebut, secDebut, anneeFin, moisFin, jourFin, heureFin, minFin, secFin;
					cout << "Mode surveillance - veuillez selectionner la periode souhaitee" << endl;
					cout << "Date de debut de periode (AAAA/MM/JJ-hh:mm:ss) : ";
					cin >> input;
					anneeDebut = atoi(input.substr(0,4).c_str());
					moisDebut = atoi(input.substr(5,2).c_str());
					jourDebut = atoi(input.substr(8,2).c_str());
					heureDebut = atoi(input.substr(11,2).c_str());
					minDebut = atoi(input.substr(14,2).c_str());
					secDebut = atoi(input.substr(17,2).c_str());
					cout << "Date de fin de periode (AAAA/MM/JJ-hh:mm:ss) : ";
					cin >> input;
					cout << endl;
					anneeFin = atoi(input.substr(0, 4).c_str());
					moisFin = atoi(input.substr(5, 2).c_str());
					jourFin = atoi(input.substr(8, 2).c_str());
					heureFin = atoi(input.substr(11, 2).c_str());
					minFin = atoi(input.substr(14, 2).c_str());
					secFin = atoi(input.substr(17, 2).c_str());

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
									capteursDefectueux = verifierDonneesCapteurs(contexte);
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
							ifstream flux(fichierMesures);
							flux.seekg(0, ios::end);
							long long int length = flux.tellg();
							flux.seekg(0, ios::beg);
							int pos = -1;
							multimap<string, double> valeursCapteurs;
							getline(flux, input);
							while (flux >> mesure) {
								if ((int)((double)(flux.tellg()) / (double)(length) * 100) > pos) {
									pos = (int)((double)(flux.tellg()) / (double)(length) * 100);
									cout << "Initialisation de l'application en cours : " << pos << " %\r";
								}
								valeursCapteurs.insert(make_pair(mesure.GetIdCapteur(),mesure.GetValeur()));
							}
							cout << endl << endl;

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
set<Capteur> * Outil::verifierDonneesCapteurs(const Contexte * contexte) const
{
	set<string> idCapteursDefectueux;
	set<Capteur> * capteursDefectueux = new set<Capteur>();

	ifstream flux(fichierMesures);
	flux.seekg(0, ios::end);
	long long int length = flux.tellg();
	flux.seekg(0, ios::beg);
	int pos = -1;

	Mesure mesure;
	string tmp;
	getline(flux, tmp);
	while (flux >> mesure)
	{
		if ((int)((double)(flux.tellg()) / (double)(length) * 100) > pos) {
			pos = (int)((double)(flux.tellg()) / (double)(length) * 100);
			cout << "Analyse des capteurs en cours : " << pos << " %\r";
		}
		if (contexte->EstDedans(mesure.GetDate()) && (mesure.GetValeur() < moyenneCapteurs.find(mesure.GetIdCapteur())->second - 10.0 || mesure.GetValeur() > moyenneCapteurs.find(mesure.GetIdCapteur())->second + 10.0))
		{
			idCapteursDefectueux.insert(mesure.GetIdCapteur());
		}
	}
	cout << endl;

	for (vector<Capteur>::const_iterator it = listeCapteurs.cbegin(); it != listeCapteurs.cend(); ++it)
	{
		if (idCapteursDefectueux.find(it->GetId()) != idCapteursDefectueux.end())
		{
			capteursDefectueux->insert(*it);
		}
	}

	return capteursDefectueux;
}

set<Capteur> * Outil::verifierCapteurs(const Contexte * contexte) const
{
	set<string> capteursFonctionnels;
	set<Capteur> * capteursDefectueux = new set<Capteur>();

	ifstream flux(fichierMesures);
	flux.seekg(0, ios::end);
	long long int length = flux.tellg();
	flux.seekg(0, ios::beg);
	int pos = -1;

	Mesure mesure;
	string tmp;
	getline(flux, tmp);
	while (flux >> mesure)
	{
		if ((int)((double)(flux.tellg()) / (double)(length) * 100) > pos) {
			pos = (int)((double)(flux.tellg()) / (double)(length) * 100);
			cout << "Analyse des capteurs en cours : " << pos << " %\r";
		}
		if (contexte->EstDedans(mesure.GetDate()))
		{
			capteursFonctionnels.insert(mesure.GetIdCapteur());
		}
	}
	cout << endl;

	for (vector<Capteur>::const_iterator it = listeCapteurs.cbegin(); it != listeCapteurs.cend(); ++it)
	{
		if (capteursFonctionnels.find(it->GetId()) == capteursFonctionnels.end())
		{
			capteursDefectueux->insert(*it);
		}
	}

	return capteursDefectueux;
}
