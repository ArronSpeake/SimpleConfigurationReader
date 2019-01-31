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
    Configuration config = reader.configuration();
  }

	TEST_METHOD(Can_Detect_Bad_File) {
    SimpleConfigurationReader reader("../resources/eyy2eb23bo7b7biy7.cfg"); // does not exist
    Assert::IsFalse(reader.good(), L"bad file should be bad");
    Configuration config = reader.configuration();
	}
	};
}