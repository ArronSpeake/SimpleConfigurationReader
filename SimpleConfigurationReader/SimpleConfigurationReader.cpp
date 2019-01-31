#include "SimpleConfigurationReader.h"

#include <fstream>
#include <sstream>

#include "Utility.h"

static bool slurp(const std::string &path, std::string &contents) {
  std::ifstream ifstream(path);
  if (!ifstream.good()) return false;

  std::stringstream stringstream;
  stringstream << ifstream.rdbuf();
  contents = stringstream.str();

  return true;
}

static void fixLineEndings(std::string &string) {
  Utility::replace(string, "\r\n", "\r");
  Utility::replace(string, "\r", "\n");

  if (string.back() != '\n') string.push_back('\n');
}

static void parseLine(const std::string& line) {
  size_t separator = line.find(':');
  if (separator == std::string::npos) __debugbreak();
  std::string key = line.substr(0, separator);
  std::string value = line.substr(separator + 1);
}

static void parse(std::string document) {
  fixLineEndings(document);
  
  std::string line;
  size_t lineStart = 0;
  while (true) {
    size_t lineEnd = document.find('\n', lineStart);
    if (lineEnd == std::string::npos) break;
    line = document.substr(lineStart, lineEnd);
    
    parseLine(line);

    lineStart = lineEnd + 1;
  }
}

SimpleConfigurationReader::SimpleConfigurationReader(const std::string &path) {
  good_ = slurp(path, contents_);
  configuration_ = Configuration();

  parse(contents_);
}

const Configuration SimpleConfigurationReader::configuration() const {
  return configuration_;
}

const bool SimpleConfigurationReader::good() const {
  return good_;
}
