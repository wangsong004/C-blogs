# Performance Comparison: std::map vs std::unordered_map in C++

In this documentation, we'll explore the performance differences between `std::map` and `std::unordered_map` in C++, focusing on insertion, lookup, and erase operations using random keys.

## Overview

`std::map` and `std::unordered_map` are both associative containers in C++ that store elements formed by a combination of a key and a mapped value. However, they differ in their underlying data structures and performance characteristics:

- **std::map**: Implemented as a balanced binary search tree (Red-Black Tree in most implementations), ensuring that all operations have a logarithmic time complexity O(log n).

- **std::unordered_map**: Implemented as a hash table, providing average constant time complexity O(1) for insert, delete, and lookup operations, assuming a good hash function and uniform distribution of keys.

## Experimental Setup

### Environment

- **Compiler**: C++11 or later supporting `<chrono>` and `<random>` libraries.
- **Hardware**: Modern CPU with sufficient RAM.

### Test Procedure

We'll conduct three main tests for both `std::map` and `std::unordered_map`:

1. **Insertion**: Inserting `num_elements` key-value pairs into the map.
2. **Lookup**: Accessing each key in the map to measure lookup time.
3. **Erase**: Removing each key from the map to measure erase time.

### Code Implementation

```cpp
#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    const int num_elements = 1000000;
    std::map<int, int> ordered_map;
    std::unordered_map<int, int> unordered_map;

    // Generate random numbers
    std::vector<int> keys(num_elements);
    std::iota(keys.begin(), keys.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(keys.begin(), keys.end(), g);

    // Insertion test
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        ordered_map[keys[i]] = i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "std::map insert duration: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        unordered_map[keys[i]] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "std::unordered_map insert duration: " << duration.count() << " seconds" << std::endl;

    // Lookup test
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        volatile int value = ordered_map[keys[i]];
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "std::map find duration: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        volatile int value = unordered_map[keys[i]];
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "std::unordered_map find duration: " << duration.count() << " seconds" << std::endl;

    // Erase test
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        ordered_map.erase(keys[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "std::map erase duration: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        unordered_map.erase(keys[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "std::unordered_map erase duration: " << duration.count() << " seconds" << std::endl;

    return 0;
}

## Conclusion
Based on the performance tests conducted, std::unordered_map demonstrates superior performance in insertion, lookup, and erase operations compared to std::map, especially with a large number of elements. However, the choice between std::map and std::unordered_map should also consider other factors such as memory overhead, iterator invalidation, and specific requirements of key ordering.

In scenarios where fast access times are critical and the order of elements does not matter, std::unordered_map is generally the preferred choice due to its constant-time complexity for most operations.