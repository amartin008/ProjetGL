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
	int nbSim = 0;
	bool quitterAnalyse = false;
	bool quitterSurveillance = false;

	string input;

	Contexte * contexte = new Contexte();
	set<Capteur>* capteursDefectueux;

	cout << "Bienvenue ! Que voulez-vous faire ?" << endl;

	cout << "Veuillez specifier les fichiers avant de commencer." << endl;
	specifierFichiers();

	do {
		cout << "1. Lancer le mode analyse" << endl;
		cout << "2. Lancer le mode surveillance" << endl;
		cout << "3. Quitter l'application" << endl;
		cout << "Votre choix : ";
		cin >> choix;
		cout << endl;
		
		if (cin.good()) {

			quitterAnalyse = 0;
			quitterSurveillance = 0;

			switch(choix) {
				case 1:
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
									bool periode;
									cout << "Calcul de la qualite de l'air" << endl;
									cout << endl;

									cout << "0. Sur une periode" << endl;
									cout << "1. Sur un moment" << endl;

									cout << endl;
									cin >> periode;

									if (periode) {
										contexte = saisieDatePeriode();
									}
									else {
										contexte = saisieDateMoment();
									}

									contexte->SetPoint(*saisiePoint());

									float rayon;
									cout << "Rayon (km) : ";
									cin >> rayon;

									contexte->SetRayon(rayon);

									cout << "Fin d'analyse." << endl;
									cout << endl;

									for (pair<string, double> p : calculerQualiteMoyenne(contexte)) {
										cout << p.first << " : " << p.second << endl;
									}

									cout << endl;
									break;
								case 2:

									cout << "Recherche des comportements de capteurs similaires" << endl;
									cout << endl;
									cout << "Saisie du centre :" << endl;

									contexte->SetPoint(*saisiePoint());
									cout << "Rayon (km) : ";
									cin >> rayon;

									contexte->SetRayon(rayon);

									
									for (pair<pair<Capteur, Capteur>, string> p : chercherCaptSimilaires(contexte))
									{
										cout << (p.first).first << " a un comportement similaire a " << (p.first).second << "dans la mesure de " << p.second << endl;
										nbSim++;
									}

									if (nbSim == 0)
									{
										cout << "Aucun couple de capteurs n'a un comportement similaire dans cette zone" << endl;
									}

									break;
								case 3:
									cout << "Recherche des caracteristiques de l'air a un point donne" << endl;
									cout << endl;

									cout << "Saisie du centre :" << endl;

									contexte->SetPoint(*saisiePoint());

									for (pair<string, double> p : trouverValeursCaract(contexte)) {
										cout << p.first << " : " << p.second << endl;
									}

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
					contexte = saisieDatePeriode();
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

vector<Capteur> Outil::GetListeCapteurs() const
{
	return listeCapteurs;
}

void Outil::setListeCapteurs(vector<Capteur> v) 
{
	listeCapteurs = v;
}

vector<Attribut> Outil::GetListeAttributs()
{
	return listeAttributs;
}

void Outil::setListeAttributs(vector<Attribut> attributs)
{
	this->listeAttributs = attributs;
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

Contexte* Outil::saisieDateMoment() {
	time_t temps = time(NULL);
	struct tm* ajd = localtime(&temps);

	int anneeDebut, moisDebut, jourDebut, heureDebut, minDebut, secDebut;

	Date debut, fin;
	Date today = Date(ajd->tm_year + 1900, ajd->tm_mon, ajd->tm_mday, ajd->tm_hour, ajd->tm_min, ajd->tm_sec);

	cout << "Date : " << endl;

	do {
		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Annee : ";
			cin >> anneeDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Mois : ";
			cin >> moisDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Jour : ";
			cin >> jourDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Heure : ";
			cin >> heureDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Minute : ";
			cin >> minDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Seconde : ";
			cin >> secDebut;
		} while (!cin.good());

		debut = Date(anneeDebut, moisDebut, jourDebut, heureDebut, minDebut, secDebut);

	} while (today <= debut);

	return new Contexte(debut, debut);
}

Contexte* Outil::saisieDatePeriode() {
	time_t temps = time(NULL);
	struct tm* ajd = localtime(&temps);

	int anneeDebut, moisDebut, jourDebut, heureDebut, minDebut, secDebut, anneeFin, moisFin, jourFin, heureFin, minFin, secFin;

	Date debut, fin;
	Date today = Date(ajd->tm_year + 1900, ajd->tm_mon, ajd->tm_mday, ajd->tm_hour, ajd->tm_min, ajd->tm_sec);

	cout << "Date de debut de periode : " << endl;
	
	do {
		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Annee : ";
			cin >> anneeDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Mois : ";
			cin >> moisDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Jour : ";
			cin >> jourDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Heure : ";
			cin >> heureDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Minute : ";
			cin >> minDebut;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Seconde : ";
			cin >> secDebut;
		} while (!cin.good());

		debut = Date(anneeDebut, moisDebut, jourDebut, heureDebut, minDebut, secDebut);
		
	} while (today <= debut);
	
	cout << endl;
	cout << "Date de fin de periode : " << endl;
	
	

	do {
		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Annee : ";
			cin >> anneeFin;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Mois : ";
			cin >> moisFin;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Jour : ";
			cin >> jourFin;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Heure : ";
			cin >> heureFin;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Minute : ";
			cin >> minFin;
		} while (!cin.good());

		do {
			if (!cin.good()) {
				cout << "Saisie incorrecte." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Seconde : ";
			cin >> secFin;
		} while (!cin.good());

		fin = Date(anneeFin, moisFin, jourFin, heureFin, minFin, secFin);

	} while (fin <= debut);

	cout << endl;

	return new Contexte(debut, fin);
}

Point * Outil::saisiePoint() {
	float lat, lng;
	
	cout << "Saisie de point : " << endl;
	cout << "Latitude : ";
	cin >> lat;
	cout << "Longitude : ";
	cin >> lng;

	return new Point(lat, lng);
}

void Outil::specifierFichiers() {
	string input;
	FILE* buffer;

	Capteur capteur;
	Attribut attribut;
	Mesure mesure;

	cout << "Les fichiers doivent etre dans le repertoire data_folder" << endl;
	cout << endl;

	do {
		cout << "Fichier concernant les capteurs : ";
		cin >> input;

		cout << endl;
		buffer = fopen(("data_folder/" + input).c_str(), "r");
		if (buffer == NULL) {
			cerr << "Fichier inexistant" << endl;
			cout << endl;
		}
		else {
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
		cout << "Fichier concernant les attributs : ";
		cin >> input;

		cout << endl;
		buffer = fopen(("data_folder/" + input).c_str(), "r");

		if (buffer == NULL) {
			cerr << "Fichier inexistant" << endl;
			cout << endl;
		}
		else {
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

	do {
		cout << "Fichier concernant les mesures : ";
		cin >> input;

		cout << endl;
		buffer = fopen(("data_folder/" + input).c_str(), "r");

		if (buffer == NULL) {
			cerr << "Fichier inexistant" << endl;
			cout << endl;
		}
		else {
			SetFichierMesures("data_folder/" + input);
			ifstream flux(fichierMesures);
			flux.seekg(0, ios::end);
			long long int length = flux.tellg();
			flux.seekg(0, ios::beg);
			int pos = -1;
			map<pair<string, string>, long int> nbValeursCapteurs;
			map<pair<string, string>, double>::iterator itMoyenneCapteurs;
			pair<string, string> pairTmp;
			getline(flux, input);
			while (flux >> mesure) {
				if ((int)((double)(flux.tellg()) / (double)(length) * 100) > pos) {
					pos = (int)((double)(flux.tellg()) / (double)(length) * 100);
					cout << "Initialisation de l'application en cours : " << pos << " %\r";
				}
				pairTmp = make_pair(mesure.GetIdCapteur(), mesure.GetIdAttribut());
				itMoyenneCapteurs = moyenneCapteurs.find(pairTmp);
				if (itMoyenneCapteurs == moyenneCapteurs.end()) {
					moyenneCapteurs.insert(make_pair(pairTmp, mesure.GetValeur()));
					nbValeursCapteurs.insert(make_pair(pairTmp, 1));
				}
				else {
					itMoyenneCapteurs->second += mesure.GetValeur();
					nbValeursCapteurs.find(pairTmp)->second += 1;
				}
			}
			cout << endl << endl;
			for (itMoyenneCapteurs = moyenneCapteurs.begin(); itMoyenneCapteurs != moyenneCapteurs.end(); ++itMoyenneCapteurs) {
				itMoyenneCapteurs->second /= nbValeursCapteurs.find(itMoyenneCapteurs->first)->second;
			}
		}
	} while (buffer == NULL);

	if (buffer != NULL) {
		fclose(buffer);
	}
}

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
			cout << "Analyse des donnees des capteurs en cours : " << pos << " %\r";
		}
		if (contexte->EstDedans(mesure.GetDate()) && (mesure.GetValeur() < moyenneCapteurs.find(make_pair(mesure.GetIdCapteur(),mesure.GetIdAttribut()))->second - 300.0 || mesure.GetValeur() > moyenneCapteurs.find(make_pair(mesure.GetIdCapteur(),mesure.GetIdAttribut()))->second + 300.0))
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

map<string, double> Outil::calculerQualiteMoyenne(const Contexte* contexte) {
	ifstream flux(fichierMesures);
	set<string> capteurConcernee;
	map<string, int> nbMesures;
	map<string, double> moyenneValeurs;

	map<string, double>::iterator it;

	Mesure mesure;
	string tmp;

	bool moment = false;

	if (contexte->GetDebut() == contexte->GetFin()) {
		moment = true;
	}

	for (Capteur c : listeCapteurs) {
		if (contexte->EstDedans(c.GetLocalisation())) {
			capteurConcernee.insert(c.GetId());
		}
	}

	getline(flux, tmp);
	while (flux >> mesure) {
		if (!moment) {
			if (capteurConcernee.find(mesure.GetIdCapteur()) != capteurConcernee.end() && contexte->EstDedans(mesure.GetDate())) {
				it = moyenneValeurs.find(mesure.GetIdAttribut());
				if (it != moyenneValeurs.end()) {
					it->second += mesure.GetValeur();
				}
				else {
					moyenneValeurs[mesure.GetIdAttribut()] = mesure.GetValeur();
				}
				nbMesures[mesure.GetIdAttribut()]++;
			}
		}
		else {
			unsigned int compteur = 0;
			Date instantDate = contexte->GetDebut();

			for (Attribut a : listeAttributs) {
				nbMesures[a.GetId()] = capteurConcernee.size();
			}

			if (capteurConcernee.find(mesure.GetIdCapteur()) != capteurConcernee.end() && contexte->GetDebut() <= mesure.GetDate()) {
				if (compteur++ > listeAttributs.size() * capteurConcernee.size()) {
					break;
				}
				it = moyenneValeurs.find(mesure.GetIdAttribut());
				if (it != moyenneValeurs.end()) {
					it->second += mesure.GetValeur();
				}
				else {
					moyenneValeurs[mesure.GetIdAttribut()] = mesure.GetValeur();
				}
			}
		}
	}
	for (pair<string,double> p : moyenneValeurs) {
		p.second /= nbMesures.find(p.first)->second;
		moyenneValeurs[p.first] = p.second;
	}

	return moyenneValeurs;
}

map <string, double> Outil::trouverValeursCaract(const Contexte* contexte) {
	ifstream flux(fichierMesures);

	map <string, double> valeursCaract;
	map<double, string> distanceCapteurs;
	
	pair<string, double> captDedans;
	map<string, double> captDehors;
	bool dehors = false;

	Mesure mesure;
	string tmp;

	for (Capteur c : listeCapteurs) {
		double distance = c.GetLocalisation().GetDistance(contexte->GetPoint());
		distanceCapteurs.insert(make_pair(distance, c.GetId()));
	}

	if ((*distanceCapteurs.begin()).first > 30) {
		dehors = true;
		for (pair<double, string> p : distanceCapteurs) {
			if (captDehors.size() <= 4) {
				captDehors.insert(make_pair(p.second, p.first));
			}
			else {
				break;
			}
		}
	}
	else {
		captDedans = make_pair((*distanceCapteurs.begin()).second, (*distanceCapteurs.begin()).first);
	}

	getline(flux, tmp);
	if (dehors) {

		map<pair<string, string>, double> nbMesures;
		map<pair<string, string>, int> compteur;
		map<pair<string, string>, double*> dixDerniers;
		map<string, double> sommeDistance;

		for (pair<string,double> c : captDehors) {
			for (Attribut a : listeAttributs) {
				dixDerniers.insert(make_pair(make_pair(c.first, a.GetId()), new double[10]));
				compteur.insert(make_pair(make_pair(c.first, a.GetId()), 0));
			}
		}

		while (flux >> mesure) {
			if (captDehors.find(mesure.GetIdCapteur()) != captDehors.end()) {
				dixDerniers[make_pair(mesure.GetIdCapteur(), mesure.GetIdAttribut())][compteur[make_pair(mesure.GetIdCapteur(), mesure.GetIdAttribut())]++ % 10] = mesure.GetValeur();
			}
		}

		for (Attribut a : listeAttributs) {
			valeursCaract[a.GetId()] = 0;
		}

		for (pair<pair<string, string>, double*> p : dixDerniers) {
			string attrId = p.first.second;
			string captId = p.first.first;

			double sum = 0;			

			for (int i = 0; i < 10; i++) {
				sum += p.second[i];
			}

			sommeDistance[p.first.second] += 1/captDehors[p.first.second];
			delete[] p.second;

			valeursCaract[p.first.second] = sum / (captDehors[p.first.second]*10);
		}

		for (pair<string, double> p : valeursCaract) {
			p.second /= sommeDistance[p.first];
			valeursCaract[p.first] = p.second;
		}
	}
	else {

		map<string, double> nbMesures;
		map<string, int> compteur;
		map<string, double*> dixDerniers;

		for (Attribut a : listeAttributs) {
			dixDerniers.insert(make_pair(a.GetId(), new double[10]));
			compteur.insert(make_pair(a.GetId(), 0));
		}

		while (flux >> mesure) {
			if (!captDedans.first.compare(mesure.GetIdCapteur())) {
				dixDerniers[mesure.GetIdAttribut()][compteur[mesure.GetIdAttribut()]++ % 10] = mesure.GetValeur();
			}
		}

		for (pair<string, double*> p : dixDerniers) {
			double sum = 0;
			for (int i = 0; i < 10; i++) {
				sum += p.second[i];
			}
			delete[] p.second;
			valeursCaract[p.first] = sum/10;
		}
	}
	return valeursCaract;
}

multimap<pair<Capteur, Capteur>, string> Outil::chercherCaptSimilaires(const Contexte * contexte)
{
	set<Capteur> capteursConcernes;
	multimap <pair<Capteur, Capteur>, string> capteursSimilaires;
	map<pair<string, string>, double> moyenneCapteursConcernes;

	set<Capteur>::iterator itSet1;
	set<Capteur>::iterator itSet2;
	map<pair<string, string>, double>::iterator itMoyenneValeurs;
	map<pair<string, string>, double>::iterator itMoyenneValeurs2;

	Mesure mesure;
	string tmp;

	for (Capteur c : listeCapteurs) {
		if (contexte->EstDedans(c.GetLocalisation()))
		{
			capteursConcernes.insert(c);
			for (pair<pair<string, string>, double> p : moyenneCapteurs)
			{
				if ((p.first).first == c.GetId())
				{
					moyenneCapteursConcernes.insert(p);
				}
			}
		}
	}

	bool comportSimilaire = false;
	for (itSet1 = capteursConcernes.begin(); itSet1 != capteursConcernes.end(); ++itSet1)
	{
		for (Attribut attr : listeAttributs)
		{
			//Recup de la moyenne des mesures pour cet attribut
			itMoyenneValeurs = moyenneCapteursConcernes.find(make_pair(itSet1->GetId(), attr.GetId()));
			if (itMoyenneValeurs != moyenneCapteursConcernes.end()) //s'il existe une mesure pour cet attribut
			{
				double valeurMoy = itMoyenneValeurs->second;

				//Comparaison avec les autres capteurs
				for (itSet2 = capteursConcernes.begin(); itSet2 != capteursConcernes.end(); ++itSet2)
				{
					if (itSet2->GetId() != itSet1->GetId())
					{
						itMoyenneValeurs2 = moyenneCapteursConcernes.find(make_pair(itSet2->GetId(), attr.GetId()));
						if (itMoyenneValeurs2 != moyenneCapteursConcernes.end())
						{
							double valeurMoy2 = itMoyenneValeurs2->second;
							if (abs(valeurMoy2 - valeurMoy) <= 1)
							{
								capteursSimilaires.insert(make_pair(make_pair(*itSet1, *itSet2), attr.GetId()));
							}
						}
					}
				}
			}
		}
	}
	return capteursSimilaires;

}