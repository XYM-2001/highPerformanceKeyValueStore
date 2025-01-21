#include "kv_store.hpp"

KVStore::KVStore() {}

bool KVStore::put(const std::string& key, const std::string& value) {
    return storage_.put(key, value);
}

bool KVStore::get(const std::string& key, std::string& value) {
    return storage_.get(key, value);
}

bool KVStore::remove(const std::string& key) {
    return storage_.remove(key);
}

bool KVStore::contains(const std::string& key) {
    std::string value;
    return storage_.get(key, value);
}

void KVStore::clear() {
    storage_.clear();
}

size_t KVStore::size() const {
    return storage_.size();
}