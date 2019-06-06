#include "stdafx.h"
#include "CppUnitTest.h"
#include "Contexte.h"
#include "Point.h"
#include "Date.h"
#include "Attribut.h"
#include "Mesure.h"
#include "Outil.h"
#include "Capteur.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// TESTS UNITAIRES
		
		TEST_METHOD(TestEstDedansPoint)
		{
			Contexte contexte(10.0,Point(-5.0,50.0));
			bool res1 = contexte.EstDedans(Point(-5.0,50.0));
			bool res2 = contexte.EstDedans(Point(-75.1, 51.0));

			Assert::AreEqual(
				true,
				res1,
				L"Test failed",
				LINE_INFO()
			);

			Assert::AreEqual(
				false,
				res2,
				L"Test failed",
				LINE_INFO()
			);
		}

		TEST_METHOD(TestEstDedansDate)
		{
			Contexte contexte(Date(2019,1,1,0,0,0),Date(2019,1,1,12,0,0));
			bool res1 = contexte.EstDedans(Date(2019,1,1,8,0,0));
			bool res2 = contexte.EstDedans(Date(2019,1,1,12,0,1));

			Assert::AreEqual(
				true,
				res1,
				L"Test failed",
				LINE_INFO()
			);

			Assert::AreEqual(
				false,
				res2,
				L"Test failed",
				LINE_INFO()
			);
		}


		// TESTS D'INTEGRATION

		TEST_METHOD(TestVerifierCapteurs)
		{
			Outil * outil = new Outil();
			outil->SetFichierCapteurs("../ProjetGlUml/data_folder/capteurs.csv");
			outil->SetFichierAttributs("../ProjetGlUml/data_folder/attributs.csv");
			outil->SetFichierMesures("../ProjetGlUml/data_folder/MesuresTestVerifierCapteurs.csv");
			Contexte * contexte = new Contexte(Date(2017,1,1,0,0,0),Date(2017,1,1,0,30,0));


			string tmp;
			Capteur capteur;
			ifstream flux(outil ->GetFichierCapteurs());
			vector<Capteur> listeCapteurs;
			getline(flux, tmp);
			while (flux >> capteur) {
				listeCapteurs.push_back(capteur);
			}
			outil->setListeCapteurs(listeCapteurs);
			set<Capteur>* capteursDefectueux =  outil->verifierCapteurs(contexte);

			set<string> resultatAttendu;
			set<string> resultatObtenu;

			ifstream flux2("../ProjetGlUml/data_folder/ResultatTestVerifierCapteurs.csv");
			while (getline(flux2, tmp))
			{
				resultatAttendu.insert(tmp);
			}

			for (auto e : *capteursDefectueux) {
				resultatObtenu.insert(e.GetId());
			}

			bool resultat = (resultatAttendu == resultatObtenu);

			Assert::AreEqual(
				true,
				resultat,
				L"Test failed",
				LINE_INFO()
			);

		}
	};
}