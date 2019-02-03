#ifndef UTILITY_H_DEFINED
#define UTILITY_H_DEFINED

#include <string>

namespace Utility {
  void replace(std::string &string, const std::string &substr, const std::string &replace);
  void strip(std::string &string, const char c = ' ');
  void stripWhitespace(std::string &string);
}

#endif // UTILITY_H_DEFINED