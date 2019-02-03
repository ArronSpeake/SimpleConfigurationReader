#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "SimpleConfigurationReader.h"
#include "Configuration.h"

namespace SimpleConfigurationReaderTests {
  TEST_CLASS(SimpleConfigurationReader_Tests) {
  public:
    TEST_METHOD(Can_Read_Empty_File) {
      SimpleConfigurationReader reader("../resources/empty.cfg");
      Assert::IsTrue(reader.good(), L"reader read a bad file"); 
    }

	  TEST_METHOD(Can_Detect_Bad_File) {
      SimpleConfigurationReader reader("../resources/eyy2eb23bo7b7biy7.cfg"); // does not exist
      Assert::IsFalse(reader.good(), L"bad file should be bad");
	  }

    TEST_METHOD(Can_Read_Single_Property) {
      SimpleConfigurationReader reader("../resources/simple.cfg");
      Configuration config = reader.configuration();
      Assert::AreEqual("myFirstValue", config["myFirstProperty"].c_str());
    }

    TEST_METHOD(Can_Read_Whitespace_Padded_Property) {
      SimpleConfigurationReader reader("../resources/spaced.cfg");
      Configuration config = reader.configuration();
      Assert::AreEqual("and spaces", config["tabsAbout"].c_str());
    }

    TEST_METHOD(Can_Read_Multiple_Properties) {
      SimpleConfigurationReader reader("../resources/multiple.cfg");
      Configuration config = reader.configuration();

      Assert::AreEqual("Nanomachines?", config["__big_boss__"].c_str());
      Assert::AreEqual("abcdefg, eh", config["alphabet"].c_str());
      Assert::AreEqual("1, Two, 3.0, four, 5f, Sixteen?", config["numbers"].c_str());
    }
	};
}
