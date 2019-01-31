#include "SimpleConfigurationReader.h"

SimpleConfigurationReader::SimpleConfigurationReader(const std::string& path) {
  good_ = false;
  configuration_ = Configuration();
}

const Configuration SimpleConfigurationReader::configuration() const {
  return configuration_;
}

const bool SimpleConfigurationReader::good() const {
  return good_;
}