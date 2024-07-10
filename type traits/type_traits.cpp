#include <iostream>
#include <type_traits>

template <typename T>
void checkTypeTraits() {
	std::cout << std::boolalpha;
	std::cout << "is_integral: " << std::is_integral<T>::value << std::endl;
	std::cout << "is_floating_point: " << std::is_floating_point<T>::value << std::endl;
	std::cout << "is_pointer: " << std::is_pointer<T>::value << std::endl;
	std::cout << "is_array: " << std::is_array<T>::value << std::endl;
	std::cout << "is_class: " << std::is_class<T>::value << std::endl;
	std::cout << "is_const: " << std::is_const<T>::value << std::endl;
}

int main() {
	std::cout << "int:" << std::endl;
	checkTypeTraits<int>();

	std::cout << "const int:" << std::endl;
		checkTypeTraits<const int>();

	std::cout << "int* :" << std::endl;
		checkTypeTraits<int*>();

	std::cout << "int[]:" << std::endl;
		checkTypeTraits<int[]>();

	std::cout << "MyClass:" << std::endl;
		class MyClass {};
	checkTypeTraits<MyClass>();

	return 0;
}