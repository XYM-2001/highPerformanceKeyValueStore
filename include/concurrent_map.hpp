#pragma once
#include <shared_mutex>
#include <unordered_map>

template<typename K, typename V>
class ConcurrentMap {
public:
    bool insert(const K& key, const V& value) {
        std::unique_lock<std::shared_mutex> lock(mutex_);
        return data_.insert({key, value}).second;
    }

    bool get(const K& key, V& value) {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        auto it = data_.find(key);
        if (it != data_.end()) {
            value = it->second;
            return true;
        }
        return false;
    }

    bool remove(const K& key) {
        std::unique_lock<std::shared_mutex> lock(mutex_);
        return data_.erase(key) > 0;
    }

    void clear() {
        std::unique_lock<std::shared_mutex> lock(mutex_);
        data_.clear();
    }

    size_t size() const {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return data_.size();
    }

private:
    mutable std::shared_mutex mutex_;
    std::unordered_map<K, V> data_;
};