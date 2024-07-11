
#include <iostream>
#include <type_traits>

//#define ENABLE_IF_FUNCTION
//#define ENABLE_IF_T_FUNCTION
#define ENABLE_IF_T_CLASS

#ifdef ENABLE_IF_FUNCTION

// Function template that is enabled only if T is an integral type
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(T value) {
    std::cout << "Integral: " << value << std::endl;
}

// Function template that is enabled only if T is a floating-point type
template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print(T value) {
    std::cout << "Floating point: " << value << std::endl;
}

int main() {
    print(10);          // Calls the integral version
    print(10.5);        // Calls the floating-point version
    // print("test");   // Error: no matching function for call to 'print'
}
#elif defined ENABLE_IF_T_FUNCTION

#include <iostream>
#include <type_traits>

// Function template that is enabled only if T is an integral type
template<typename T>
std::enable_if_t<std::is_integral<T>::value, void>
print(T value) {
    std::cout << "Integral: " << value << std::endl;
}

// Function template that is enabled only if T is a floating-point type
template<typename T>
std::enable_if_t<std::is_floating_point<T>::value, void>
print(T value) {
    std::cout << "Floating point: " << value << std::endl;
}

int main() {
    print(10);          // Calls the integral version
    print(10.5);        // Calls the floating-point version
    // print("test");   // Error: no matching function for call to 'print'
}
#else

#include <iostream>
#include <type_traits>

// Class template specialization that is enabled only if T is an integral type
template<typename T, typename Enable = void>
class MyClass;

// Specialization for integral types
template<typename T>
class MyClass<T, std::enable_if_t<std::is_integral<T>::value>> {
public:
    void display() {
        std::cout << "Integral type" << std::endl;
    }
};

// Specialization for floating-point types
template<typename T>
class MyClass<T, std::enable_if_t<std::is_floating_point<T>::value>> {
public:
    void display() {
        std::cout << "Floating-point type" << std::endl;
    }
};

int main() {
    MyClass<int> intClass;
    intClass.display(); // Outputs: Integral type

    MyClass<double> floatClass;
    floatClass.display(); // Outputs: Floating-point type

    // MyClass<std::string> strClass; // Error: no matching template specialization for type
}

#endif
