#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void increment_by_value(int& element, const int& increment) {
    element += increment;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int increment_value = 10;

    // Use std::for_each to traverse vec and use std::ref to pass increment_value by reference
    std::for_each(vec.begin(), vec.end(), std::bind(increment_by_value, std::placeholders::_1, std::ref(increment_value)));

    // Print the modified vec
    for (const int& value : vec) {
        std::cout << value << " ";  // Output: 11 12 13 14 15
    }
    std::cout << std::endl;

    return 0;
}
