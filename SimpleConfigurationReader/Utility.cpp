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
  while ((string.length() > 0) && (string.front() == c)) {
    string.erase(string.begin());
  }

  while ((string.length() > 0) && (string.back() == c)) {
    string.erase(string.end() - 1);
  }
}

static const bool isWhitespace(const char c) {
  const char *whitespace = " \t\n\v\f\r";
  for (size_t i = 0; i < 7; i++)
    if (c == whitespace[i]) return true;
  return false;
}

void Utility::stripWhitespace(std::string &string) {
  while ((string.length() > 0) && isWhitespace(string.front())) {
    string.erase(string.begin());
  }

  while ((string.length() > 0) && isWhitespace(string.back())) {
    string.erase(string.end() - 1);
  }
}
