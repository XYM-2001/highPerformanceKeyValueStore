#include "storage_engine.hpp"

StorageEngine::StorageEngine() {}

bool StorageEngine::put(const std::string& key, const std::string& value) {
    bool success = data_.insert(key, value);
    if (success) {
        persistence_.saveToFile(key, value);
    }
    return success;
}

bool StorageEngine::get(const std::string& key, std::string& value) {
    return data_.get(key, value) || persistence_.loadFromFile(key, value);
}

bool StorageEngine::remove(const std::string& key) {
    bool success = data_.remove(key);
    if (success) {
        persistence_.removeFromFile(key);
    }
    return success;
}

bool StorageEngine::contains(const std::string& key) {
    std::string value;
    return get(key, value);
}

void StorageEngine::clear() {
    data_.clear();
    persistence_.clearAll();
}

size_t StorageEngine::size() const {
    return data_.size();
}