#pragma once
#include <string>

class Persistence {
public:
    bool saveToFile(const std::string& key, const std::string& value);
    bool loadFromFile(const std::string& key, std::string& value);
    bool removeFromFile(const std::string& key);
    void clearAll();
};