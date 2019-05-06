/*************************************************************************
                           Date  -  description
                             -------------------
    début                : $06/05/2019$
    copyright            : (C) $2019$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( Date_H )
#define Date_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//
//------------------------------------------------------------------------

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    int GetAnnee();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void SetAnnee(int annee);
    
    int GetMois();
    
    void SetMois(int mois);
    
    int GetJour();
    
    void SetJour(int jour);
    
    int GetHeure();
    
    void SetHeure(int heure);
    
    int GetMin();
    
    void SetMin(int min);
    
    int GetSec();
    
    void SetSec(int sec);


//------------------------------------------------- Surcharge d'opérateurs
    //Date & operator = ( const Date & unDate );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Date ( const Date & unDate );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Date (int annee, int mois, int jour, int heure, int min, int sec);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Date ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	int annee;
	int mois;
	int jour;
	int heure;
	int min;
	int sec;

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // Date_H

