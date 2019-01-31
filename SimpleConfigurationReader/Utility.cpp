#include "Utility.h"

void Utility::replace(std::string &string, const std::string &substr, const std::string &replace) {
  size_t i = 0;
  while (true) {
    i = string.find(substr, i); // Find substring at or after i-th char.
    if (i == std::string::npos) break;

    string.erase(i, substr.length());
    string.insert(i, replace);

    i += replace.length();
  }
}