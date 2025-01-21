#include <cassert>
#include "kv_store.hpp"

void test_basic_operations() {
    KVStore store;
    
    assert(store.put("key1", "value1"));
    
    std::string value;
    assert(store.get("key1", value));
    assert(value == "value1");
    
    assert(store.remove("key1"));
    assert(!store.get("key1", value));
}

int main() {
    test_basic_operations();
    return 0;
}