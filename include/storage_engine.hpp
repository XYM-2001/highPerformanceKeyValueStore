#pragma once
#include "concurrent_map.hpp"
#include "persistence.hpp"

class StorageEngine {
public:
    StorageEngine();
    bool put(const std::string& key, const std::string& value);
    bool get(const std::string& key, std::string& value);
    bool remove(const std::string& key);
    bool contains(const std::string& key);
    void clear();
    size_t size() const;

private:
    ConcurrentMap<std::string, std::string> data_;
    Persistence persistence_;
};