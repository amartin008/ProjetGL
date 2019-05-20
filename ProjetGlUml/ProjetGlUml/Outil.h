/*************************************************************************
                           Outil  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Outil> (fichier Outil.h) ----------------
#if ! defined ( OUTIL_H )
#define OUTIL_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>

#include "Capteur.h"
#include "Attribut.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Outil>
//
//
//------------------------------------------------------------------------

class Outil
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void lancerOutil();
	
	std::string GetFichierCapteurs();
    
    void SetFichierCapteurs(std::string fichierCapteurs);
    
    std::string GetFichierMesures();
    
    void SetFichierMesures(std::string fichierMesures);
    
    std::string GetFichierAttributs();
    
    void SetFichierAttributs(std::string fichierAttributs);


//------------------------------------------------- Surcharge d'opérateurs
    //Outil & operator = ( const Outil & unOutil );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Outil ( const Outil & unOutil );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Outil();
    // Mode d'emploi :
    //
    // Contrat :
    //

	// Mode d'emploi :
	//
	// Contrat :
	//

    virtual ~Outil();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	std::string fichierCapteurs;
	std::string fichierMesures;
	std::string fichierAttributs;
	std::map<string,float> moyenneCapteurs;
	std::multimap<string, string> typeMesuresCapteurs;

	std::vector<Capteur> capteurs;
	std::vector<Attribut> attributs;
};

//-------------------------------- Autres définitions dépendantes de <Outil>

#endif // OUTIL_H

