/*************************************************************************
                           Date - description
                             -------------------
    début                : 06/05/2019
    copyright            : (C) Atmospher'IF par La Mims Team
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( Date_H )
#define Date_H
using namespace std; 

//------------------------------------------------------------------------
// Rôle de la classe <Date>
// La classe Date permet de générer un objet Date correspondant à un moment
// donné. Il est constitué d'une date (année, mois, jour) et d'une heure
// (heure, minutes, secondes).
//------------------------------------------------------------------------

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int GetAnnee() const;
	
    void SetAnnee(int annee);
    
    int GetMois() const;
    
    void SetMois(int mois);
    
    int GetJour() const;
    
    void SetJour(int jour);
    
    int GetHeure() const;
    
    void SetHeure(int heure);
    
    int GetMin() const;
    
    void SetMin(int min);
    
    int GetSec() const;
    
    void SetSec(int sec);

//-------------------------------------------- Constructeurs - destructeur
	
    Date();
    // Mode d'emploi :
    // Constructeur par défaut de la classe Date
	
    Date(int annee, int mois, int jour, int heure, int min, int sec);
    // Mode d'emploi :
    // Constructeur de la classe Date. Initialise les attraibuts entrés 
    // en paramètre
	
    virtual ~Date ( );
    // Mode d'emploi :
    // Destructeur par défaut de la classe Date

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
	int annee;
	int mois;
	int jour;
	int heure;
	int min;
	int sec;
};

#endif // Date_H

