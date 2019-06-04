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

		TEST_METHOD(Test)
		{

		}
	};
}