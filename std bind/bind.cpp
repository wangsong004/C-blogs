#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void increment_by_value(int& element, const int& increment) {
    element += increment;
}

void print_sum(int a, int b) {
	std::cout << "Sum: " << (a + b) << std::endl;
}
void print_values(int a, int b, int c) {
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
}

class MyClass {
public:
	void display(int x) const {
		std::cout << "Value: " << x << std::endl;
	}
};


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

	auto bound_func = std::bind(print_sum, 10, std::placeholders::_1);
	// 现在调用 bound_func 时，只需要提供第二个参数
	bound_func(20); // 输出: Sum: 30

	auto bound_func1 = std::bind(print_values, std::placeholders::_2, 20, std::placeholders::_1);

	// 调用时第一个传入的参数对应 `_1`，第二个对应 `_2`
	bound_func1(30, 10); // 输出: a: 10, b: 20, c: 30


	MyClass my_object;
	auto bound_func2 = std::bind(&MyClass::display, &my_object, std::placeholders::_1);

	bound_func2(42); // 输出: Value: 42


    return 0;
}
