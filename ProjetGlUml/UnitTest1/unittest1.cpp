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
		
		TEST_METHOD(TestEstDedansPoint)
		{
			Contexte contexte(10.0,Point(-5.0,50.0));
			bool res1 = contexte.EstDedans(Point(-5.0,50.0));
			bool res2 = contexte.EstDedans(Point(-5.1, 51.0));

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

		TEST_METHOD(TestVerifierCapteurs)
		{
			Outil * outil = new Outil();
			outil->SetFichierCapteurs("data_folder/capteurs.csv");
			outil->SetFichierAttributs("data_folder/attributs.csv");
			outil->SetFichierMesures("data_folder/MesuresTestVerifierCapteurs.csv");
			Contexte * contexte = new Contexte(Date(2017,1,1,0,0,0),Date(2017,1,1,0,30,0));

			set<string> capteursFonctionnels;
			set<Capteur> capteursDefectueux;
			ifstream flux(outil->GetFichierMesures());
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
			vector<Capteur> listeCapteurs = outil->GetListeCapteurs();
			for (vector<Capteur>::const_iterator it = listeCapteurs.cbegin(); it != listeCapteurs.cend(); ++it)
			{
				if (capteursFonctionnels.find(it->GetId()) == capteursFonctionnels.end())
				{
					capteursDefectueux.insert(*it);
				}
			}
			delete contexte;
			delete outil;

			set<string> resultatAttendu;
			ifstream fluxResultat("data_folder/ResultatTestVerifierCapteurs.csv");
			while (getline(fluxResultat, tmp))
			{
				resultatAttendu.insert(tmp);
			}

			set<string> resultatObtenu;
			for (set<Capteur>::const_iterator it = capteursDefectueux.cbegin(); it != capteursDefectueux.cend(); ++it)
			{
				resultatObtenu.insert(it->GetId());
			}

			bool res = false;
			if (resultatObtenu == resultatAttendu)
			{
				res = true;
			}

			Assert::AreEqual(
				true,
				res,
				L"Test failed",
				LINE_INFO()
			);
		}
	};
}