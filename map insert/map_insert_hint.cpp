#include <iostream>
#include <map>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
	const int num_elements = 10000000; // Number of elements to insert
	std::vector<int> random_numbers(num_elements);

	// Generate one million random numbers and sort them
	for (int i = 0; i < num_elements; ++i) {
		random_numbers[i] = rand();
	}
	std::sort(random_numbers.begin(), random_numbers.end());

	std::map<int, int> map;

	// Measure the start time for insertions with hint
	auto start_with_hint = std::chrono::high_resolution_clock::now();

	// Continuous insertion using hint parameter
	auto hint = map.begin(); // Initial hint iterator, can be set to other positions
	for (int i = 0; i < num_elements; ++i) {
		hint = map.insert(hint, { random_numbers[i], i });
	}

	// Measure the end time for insertions with hint
	auto end_with_hint = std::chrono::high_resolution_clock::now();

	// Calculate the duration of insertions with hint
	auto duration_with_hint = std::chrono::duration_cast<std::chrono::milliseconds>(end_with_hint - start_with_hint).count();
	std::cout << "Time taken for " << num_elements << " insertions with hint: " << duration_with_hint << " ms" << std::endl;

	// Clear the map
	map.clear();

	// Measure the start time for insertions without hint
	auto start_without_hint = std::chrono::high_resolution_clock::now();

	// Continuous insertion without using hint parameter
	for (int i = 0; i < num_elements; ++i) {
		map.insert({ random_numbers[i], i });
	}

	// Measure the end time for insertions without hint
	auto end_without_hint = std::chrono::high_resolution_clock::now();

	// Calculate the duration of insertions without hint
	auto duration_without_hint = std::chrono::duration_cast<std::chrono::milliseconds>(end_without_hint - start_without_hint).count();
	std::cout << "Time taken for " << num_elements << " insertions without hint: " << duration_without_hint << " ms" << std::endl;

	return 0;
}
