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
}

static void parse(std::string document) {
  fixLineEndings(document);
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
