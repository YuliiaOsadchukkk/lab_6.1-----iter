#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1 --- iter/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61iter
{
	TEST_CLASS(UnitTest61iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int mass[23] = {50,-20,64,17,42,74,20,53,47,70,-2,63,29,40,45,30,-12,17,14,-1,10,35,-17 },
				count = 0,
				sum = 0;
			do_stuff(mass, 24, count, sum);
			Assert::AreEqual(count, 8);
			Assert::AreEqual(sum, 306);
			Assert::AreEqual(mass[0], 50);
			Assert::AreEqual(mass[22], -17);
		}
	};
}
