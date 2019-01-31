#include "SimpleConfigurationReader.h"

#include <fstream>

SimpleConfigurationReader::SimpleConfigurationReader(const std::string& path) {
  std::ifstream ifstream(path);
  good_ = ifstream.good();

  configuration_ = Configuration();
}

const Configuration SimpleConfigurationReader::configuration() const {
  return configuration_;
}

const bool SimpleConfigurationReader::good() const {
  return good_;
}