#include "Configuration.h"


Configuration::Configuration() {

}

Configuration::Configuration(const std::vector<Property> &properties) {
  for (const Property &prop : properties) {
    map_[prop.key] = prop.value;
  }
}

const std::string Configuration::operator[](const std::string& key) const {
  bool hasKey = (map_.find(key) != map_.end()); // Throw on fail?
  return hasKey ? map_.at(key) : "";
}
