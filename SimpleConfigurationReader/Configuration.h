#ifndef CONFIGURATION_H_DEFINED
#define CONFIGURATION_H_DEFINED

#include <string>
#include <unordered_map>
#include <vector>

struct Property {
  std::string key;
  std::string value;
};

struct Configuration {
public:
  Configuration();
  Configuration(const std::vector<Property> &properties);

  const bool keyExists(const std::string& key) const;
  const std::string operator[](const std::string& key) const;
private:
  std::unordered_map<std::string, std::string> map_;
};

#endif // CONFIGURATION_H_DEFINED
