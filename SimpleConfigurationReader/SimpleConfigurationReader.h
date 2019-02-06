#ifndef SIMPLE_CONFIGURATION_READER_H_DEFINED
#define SIMPLE_CONFIGURATION_READER_H_DEFINED

#include <string>

#include "Configuration.h"

class SimpleConfigurationReader {
public:
  SimpleConfigurationReader(const std::string& path);

  const bool good() const;
  const Configuration configuration() const;
  const std::vector<size_t> errorLines() const;
private:
  bool good_;
  std::string contents_;
  std::vector<size_t> errorLines_;
  Configuration configuration_;
};

#endif // SIMPLE_CONFIGURATION_READER_H_DEFINED
