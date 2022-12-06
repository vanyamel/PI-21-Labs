#include "pch.h"
#include "CppUnitTest.h"
#include "../Levenstein/Levenstein.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLevenstein
{
	TEST_CLASS(UnitTestLevenstein)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string s1 = "abc";
			std::string s2 = "abc";
			levenstein(s1, s2);
			Assert::AreEqual(0, 0);
			
		}

		TEST_METHOD(TestMethod2)
		{
			std::string s1 = "abc";
			std::string s2 = "ab";
			levenstein(s1, s2);
			Assert::AreEqual(0, 1);

		}
	};
}
