#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include< numeric >

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
