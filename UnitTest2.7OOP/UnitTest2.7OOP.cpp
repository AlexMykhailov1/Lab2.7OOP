#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2.7OOP/Date.h"
#include "../Lab2.7OOP/Date.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest27OOP
{
	TEST_CLASS(UnitTest27OOP)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Date D1(2005, 10, 20);
			unsigned int y = 2005;
			Assert::AreEqual(y, D1.GetYear());
		}
	};
}
