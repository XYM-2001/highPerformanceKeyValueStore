cmake_minimum_required(VERSION 3.10)
project(kv_store)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include tests)

# Create main library
add_library(kv_store_lib
    src/kv_store.cpp
    src/persistence.cpp
    src/storage_engine.cpp
)

# Create tests executable
add_executable(kv_store_tests
    tests/kv_store_test.cpp
)

# Create benchmark executable
add_executable(kv_store_benchmark
    tests/benchmark_test.cpp
)

# Link tests and benchmark with main library
target_link_libraries(kv_store_tests kv_store_lib)
target_link_libraries(kv_store_benchmark kv_store_lib)