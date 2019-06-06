/*************************************************************************
                           Outil - description
                             -------------------
    début                : 06/05/2019
    copyright            : (C) Atmospher'IF par La Mims Team
*************************************************************************/

//---------- Interface de la classe <Outil> (fichier Outil.h) ----------------
#if ! defined ( OUTIL_H )
#define OUTIL_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <time.h>

#include "Capteur.h"
#include "Attribut.h"
#include "Contexte.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Outil>
//Cette classe est le coeur de l'application.
//l'objet <Outil> est créé à partir des emplacements des fichiers CSV 
//saisis par l'utilisateur et contenant les données nécessaires à l’analyse 
//et à la surveillance. Une fois les attributs initialisés, et donc toutes 
//les données utiles stockées, on pourra invoquer les différentes
//méthodes(donc nos algorithmes) suivant les besoins de l’utilisateur.
//
//------------------------------------------------------------------------

class Outil 
{
//----------------------------------------------------------------- PUBLIC

public:


//----------------------------------------------------- Méthodes publiques
    void lancerOutil();
	
    string GetFichierCapteurs() const;
    
    void SetFichierCapteurs(string fichierCapteurs) ;
    
    string GetFichierMesures() const;
    
    void SetFichierMesures(string fichierMesures);
    
    string GetFichierAttributs() const;
    
    void SetFichierAttributs(string fichierAttributs);

	vector<Capteur> GetListeCapteurs() const;

	void setListeCapteurs(vector<Capteur> capteurs);
	
	vector<Attribut> GetListeAttributs();

	void setListeAttributs(vector<Attribut> attributs);

	set<Capteur> * verifierCapteurs(const Contexte * contexte) const;
	//Mode d'emploi :
	//méthode permettant de vérifier le bon fonctionnement des capteurs
	//durant la période définie dans l'objet Contexte passé en paramètre.
	//Elle retourne la liste des capteurs n'ayant pas effectué de mesures
	//pendant cette période.

	map<string, double> calculerQualiteMoyenne(const Contexte * contexte);
	//Mode d'emploi :
	//méthode permettant de calculer la qualité moyenne de l'air dans la zone
	//définie par le contexte passé en paramètre.
	//Si une date de fin est définie dans le contexte, le calcul
	//est fait entre la date de début et cette date de fin. Sinon, le calcul est 
	//effectué à un moment donné, correspondant à la date de début renseignée.
	//La méthode retourne la map qui à chaque type de gaz associe les moyennes
	//des mesures effectuées dans le contexte.

//-------------------------------------------- Constructeurs - destructeur

    Outil();
    // Mode d'emploi :
    //Constructeur par défaut de la classe Outil


    virtual ~Outil();
    // Mode d'emploi :
    //Destructeur de la classe Outil

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	Contexte * saisieDatePeriode();

	Contexte* saisieDateMoment();

	Point * saisiePoint();

	void specifierFichiers();

	set<Capteur> * verifierDonneesCapteurs(const Contexte * contexte) const;
	//Mode d'emploi :
	//méthode permettant de vérifier les données envoyées par les capteurs
	//durant la période définie dans l'objet Contexte passé en paramètre.
	//Elle retourne la liste des capteurs ayant effectué des mesures abherrantes
	//sur cette période.

	multimap<pair<Capteur, Capteur>,string> chercherCaptSimilaires(const Contexte * contexte);
	//Mode d'emploi :
	//méthode permettant de trouver les capteurs ayant des comportements similaires
	//se trouvant dans la zone définie par le contexte passé en paramètre.
	//Elle retourne la multimap contenant les paires de capteurs ayant envoyé 
	//des données similaires dans l'ensemble, associées aux types
	//de mesure correspondants.

	map <string, double> trouverValeursCaract(const Contexte * contexte);
	//Mode d'emploi :
	//méthode permettant de trouver les caractéristiques de l'air en un point
	//donné dans le contexte passé en paramètre.
	//Elle retourne la map qui à chaque type de gaz associe les moyennes
	//des mesures effectuées au niveau de ce point

//----------------------------------------------------- Attributs protégés
	string fichierCapteurs; 
	//emplacement du fichier décrivant l’ensemble des capteurs

	string fichierAttributs;
	//emplacement du fichier décrivant les différents types de mesures

	string fichierMesures;
	//emplacement du fichier contenant les mesures des capteurs

	map<pair<string,string>,double> moyenneCapteurs;
	//conteneur map qui associe à chaque capteur d’id sensorID(string), 
	//la moyenne des mesures effectuées par celui - ci(int).
	//Cet attribut sera utilisé par la suite pour la vérification de la
	//fiabilité des données des capteurs.

	multimap<string, string> typeMesuresCapteurs;
	//conteneur multimap <string, string> qui associe à chaque capteur 
	//d’id sensorID(la clé string), le type de gaz mesuré(la valeur string).
	//Cet attribut sera utilisée pour les opérations d’analyse dans lesquels nous
	//devront relever les valeurs des mesures par type de gaz.

	vector<Capteur> listeCapteurs;
	//liste de tous les capteurs présents sur le territoire
	//initialisée par la lecture du fichier fichierCapteurs

	vector<Attribut> listeAttributs;
	//liste de tous les types de mesures effectuées par les capteurs
	//initialisée par la lecture du fichier fichiersAttributs

	
};


#endif // OUTIL_H
