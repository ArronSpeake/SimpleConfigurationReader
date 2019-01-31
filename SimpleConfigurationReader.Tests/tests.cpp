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

	};
}