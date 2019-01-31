#ifndef CONFIGURATION_H_DEFINED
#define CONFIGURATION_H_DEFINED

#include <string>

struct Configuration {
public:
  Configuration();
  const std::string operator[](const std::string& key) const;
};

#endif // CONFIGURATION_H_DEFINED
