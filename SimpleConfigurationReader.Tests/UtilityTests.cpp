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

    TEST_METHOD(Can_Replace_Multiple_Single_Chars) {
      std::string string = "abcacbdaadfa";
      Utility::replace(string, "a", "e");
      Assert::AreEqual("ebcecbdeedfe", string.c_str());
    }

    TEST_METHOD(Can_Replace_Multiple_Chars) {
      std::string string = "abdbcabcaddcbacbacbbcab";
      Utility::replace(string, "bb", "hello");
      Assert::AreEqual("abdbcabcaddcbacbachellocab", string.c_str());
    }

    TEST_METHOD(Can_Replace_Multiple_Multiple_Chars) {
      std::string string = "abbdbbcabcaddcbbacbacbbcab";
      Utility::replace(string, "bb", "hello");
      Assert::AreEqual("ahellodhellocabcaddchelloacbachellocab", string.c_str());
    }

    TEST_METHOD(Can_Replace_Chars_With_None) {
      std::string string = "ababababab";
      Utility::replace(string, "a", "");
      Assert::AreEqual("bbbbb", string.c_str());
    }

    TEST_METHOD(Cant_Replace_None_With_Anything) {
      std::string string = "ababababab";
      try {
        Utility::replace(string, "", "wow");
        Assert::Fail(L"No exception was thrown.");
      } catch (std::invalid_argument) {
        return;
      } catch (std::exception) {
        Assert::Fail(L"The incorrect exception was thrown.");
      }
    }
  };
}
