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
      Assert::AreEqual(config["myFirstProperty"].c_str(), "myFirstValue");
    }
	};
}
