#include "SimpleConfigurationReader.h"

#include <fstream>
#include <sstream>

static bool slurp(const std::string &path, std::string &contents) {
  std::ifstream ifstream(path);
  if (!ifstream.good()) return false;

  std::stringstream stringstream;
  stringstream << ifstream.rdbuf();
  contents = stringstream.str();

  return true;
}

SimpleConfigurationReader::SimpleConfigurationReader(const std::string &path) {
  good_ = slurp(path, contents_);
  configuration_ = Configuration();
}

const Configuration SimpleConfigurationReader::configuration() const {
  return configuration_;
}

const bool SimpleConfigurationReader::good() const {
  return good_;
}
