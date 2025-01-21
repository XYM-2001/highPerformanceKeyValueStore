#pragma once
#include <string>
#include "concurrent_map.hpp"
#include "storage_engine.hpp"

class KVStore {
public:
    KVStore();
    bool put(const std::string& key, const std::string& value);
    bool get(const std::string& key, std::string& value);
    bool remove(const std::string& key);
    bool contains(const std::string& key);
    void clear();
    size_t size() const;

private:
    StorageEngine storage_;
};