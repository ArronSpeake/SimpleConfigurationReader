#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Utility.h"

#include <string>

namespace UtilityTests {
  TEST_CLASS(Utility_Tests) {
public:
    TEST_METHOD(Can_Replace_Single_Chars) {
      std::string string = "abcd";
      Utility::replace(string, "a", "e");
      Assert::AreEqual("ebcd", string.c_str());
    }
  };
}
