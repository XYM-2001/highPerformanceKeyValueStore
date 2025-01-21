#include <chrono>
#include <iostream>
#include "kv_store.hpp"

void run_benchmark() {
    KVStore store;
    const int num_operations = 10000;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < num_operations; ++i) {
        store.put("key" + std::to_string(i), "value" + std::to_string(i));
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Time taken for " << num_operations << " operations: " 
              << duration.count() << "ms\n";
}

// Main function that runs both tests and benchmarks
int main() {
    std::cout << "Running unit tests...\n";
    test_basic_operations();
    std::cout << "Unit tests passed!\n\n";

    std::cout << "Running benchmark...\n";
    run_benchmark();
    return 0;
}