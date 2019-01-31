#include "Utility.h"

#include <stdexcept>

void Utility::replace(std::string &string, const std::string &substr, const std::string &replace) {
  size_t i = 0;

  if (substr.length() == 0) throw std::invalid_argument("substr cannot be zero-length.");

  while (true) {
    i = string.find(substr, i); // Find substring at or after i-th char.
    if (i == std::string::npos) break;

    string.erase(i, substr.length());
    string.insert(i, replace);

    i += replace.length();
  }
}

void Utility::strip(std::string &string, const char c) {
  // TODO
}