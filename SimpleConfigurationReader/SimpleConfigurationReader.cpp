#include "SimpleConfigurationReader.h"

#include <fstream>
#include <sstream>
#include <vector>

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
  if (string.length() == 0) return;

  Utility::replace(string, "\r\n", "\r");
  Utility::replace(string, "\r", "\n");

  if (string.back() != '\n') string += '\n';
}

static bool formatKey(std::string &key) {
  Utility::stripWhitespace(key);
  return (key.length() != 0);
}

static bool formatValue(std::string &value) {
  Utility::stripWhitespace(value);

  if ( (value.length() < 2)
    || (value.front() != '"')
    || (value.back() != '"'))
    return false;

  value = value.substr(1, value.length() - 2);
  return true;
}

static bool parseLine(const std::string& line, Property &prop) {
  size_t separator = line.find(':');
  if (separator == std::string::npos) return false;
  std::string key = line.substr(0, separator);
  std::string value = line.substr(separator + 1);

  bool isValid = formatKey(key) && formatValue(value);

  prop = { key, value };
  return isValid;
}

Configuration SimpleConfigurationReader::parse(std::string document) {
  fixLineEndings(document);
  
  std::string line;
  std::vector<Property> properties;
  std::vector<size_t> badLines;
  size_t lineStart = 0;
  size_t lineNo = 0;

  while (true) {
    size_t lineEnd = document.find('\n', lineStart);
    if (lineEnd == std::string::npos) break;
    line = document.substr(lineStart, lineEnd - lineStart);
    
    Property prop;
    bool isValid = parseLine(line, prop);

    if (isValid) {
      properties.push_back(prop);
    } else {
      badLines.push_back(lineNo);
    }

    lineStart = lineEnd + 1;
    lineNo++;
  }

  errorLines_ = badLines;
  return Configuration(properties);
}

SimpleConfigurationReader::SimpleConfigurationReader(const std::string &path) {
  good_ = slurp(path, contents_);
  configuration_ = (good_ ? parse(contents_) : Configuration());
}

const Configuration SimpleConfigurationReader::configuration() const {
  return configuration_;
}

const bool SimpleConfigurationReader::good() const {
  return good_;
}

const std::vector<size_t> SimpleConfigurationReader::errorLines() const {
  return errorLines_;
}