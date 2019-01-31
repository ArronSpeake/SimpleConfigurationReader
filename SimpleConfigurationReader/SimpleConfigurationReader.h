#ifndef SIMPLE_CONFIGURATION_READER_H_DEFINED
#define SIMPLE_CONFIGURATION_READER_H_DEFINED

#include <string>

#include "Configuration.h"

class SimpleConfigurationReader {
public:
  SimpleConfigurationReader(const std::string& path);
  const Configuration configuration() const;
  const bool good() const;
private:
  bool good_;
  Configuration configuration_;
};

#endif // SIMPLE_CONFIGURATION_READER_H_DEFINED