#include "persistence.hpp"
#include <fstream>
#include <filesystem>

bool Persistence::saveToFile(const std::string& key, const std::string& value) {
    std::ofstream file("data/" + key, std::ios::binary);
    if (!file) return false;
    file.write(value.c_str(), value.size());
    return true;
}

bool Persistence::loadFromFile(const std::string& key, std::string& value) {
    std::ifstream file("data/" + key, std::ios::binary);
    if (!file) return false;
    value.assign(std::istreambuf_iterator<char>(file), {});
    return true;
}

bool Persistence::removeFromFile(const std::string& key) {
    return std::filesystem::remove("data/" + key);
}

void Persistence::clearAll() {
    for (const auto& entry : std::filesystem::directory_iterator("data")) {
        std::filesystem::remove(entry.path());
    }
}