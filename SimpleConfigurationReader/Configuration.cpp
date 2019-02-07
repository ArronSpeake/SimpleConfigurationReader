#include "Configuration.h"

Configuration::Configuration() { }

Configuration::Configuration(const std::vector<Property> &properties) {
  for (const Property &prop : properties) {
    map_[prop.key] = prop.value;
  }
}

const std::unordered_map<std::string, std::string> &Configuration::map() const {
  return std::unordered_map<std::string, std::string>();
}

const bool Configuration::keyExists(const std::string& key) const {
  return (map_.find(key) != map_.end());
}

const std::string Configuration::operator[](const std::string& key) const {
  bool hasKey = (map_.find(key) != map_.end());
  if (!hasKey) throw std::invalid_argument("The provided key does not exist.");
  return map_.at(key);
}
