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

    TEST_METHOD(Throw_On_Bad_Config_Key) {
      try {
        Configuration config;
        std::string y = config["Key That Doesn't Exist"];

        Assert::Fail(L"No exception was thrown.");
      } catch (std::invalid_argument) {
        return;
      } catch (std::exception) {
        Assert::Fail(L"The incorrect exception was thrown.");
      }
    }

    TEST_METHOD(Can_Find_Errors_In_File) {
      SimpleConfigurationReader reader("../resources/error.cfg");
      std::vector<size_t> actual = reader.errorLines();
      
      const std::vector<size_t> expected = {
        0, 2, 3, 4, 7, 8, 9, 10
      };

      Assert::AreEqual(expected.size(), actual.size());

      for (size_t i = 0; i < expected.size(); i++) {
        Assert::AreEqual(expected[i], actual[i]);
      }
    }

    TEST_METHOD(Can_Detect_Key_Existence) {
      SimpleConfigurationReader reader("../resources/multiple.cfg");
      Configuration config = reader.configuration();

      Assert::IsTrue(config.keyExists("numbers"));
      Assert::IsFalse(config.keyExists("ABCDE, One I'll count Two Three."));
    }

    TEST_METHOD(Can_Access_Inner_Map) {
      SimpleConfigurationReader reader("../resources/multiple.cfg");
      Configuration config = reader.configuration();
      std::unordered_map<std::string, std::string> map = config.map();

      const std::vector<std::string> keys = {
        "Nanomachines?", "abcdefg, eh", "1, Two, 3.0, four, 5f, Sixteen?"
      };

      std::unordered_map<std::string, std::string> expected = {
        { "Nanomachines?", "__big_boss__" },
        { "abcdefg, eh", "alphabet" },
        { "1, Two, 3.0, four, 5f, Sixteen?", "numbers" }
      };

      Assert::AreEqual(expected.size(), map.size());
      for (const std::string &key : keys) {
        Assert::AreEqual(expected[key], map[key]);
      }
    }
	};
}
