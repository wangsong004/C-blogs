
# Understanding `std::enable_if` and `std::enable_if_t` in C++

`std::enable_if` and `std::enable_if_t` are utilities in the `<type_traits>` library that are used to conditionally enable or disable function templates or class template specializations based on type traits. They are primarily used for SFINAE (Substitution Failure Is Not An Error), a powerful feature in C++ template metaprogramming.

## `std::enable_if`

`std::enable_if` is a template that has two parameters:
1. `Condition`: A compile-time boolean constant.
2. `Type`: The type that will be returned if `Condition` is true (defaults to `void`).

If `Condition` is true, `std::enable_if` will have a member `type` which is defined as `Type`. If `Condition` is false, `std::enable_if` will not have a `type` member, leading to a substitution failure in the context where it is used, and causing the compiler to discard the template.

### Syntax

```cpp
template<bool Condition, class Type = void>
struct enable_if {};
 
template<class Type>
struct enable_if<true, Type> { typedef Type type; };
```

## `std::enable_if_t`

`std::enable_if_t` is a helper alias template that simplifies the use of `std::enable_if`. It directly resolves to the type if the condition is true and avoids the need to use the `typename` keyword.

### Syntax

```cpp
template<bool Condition, class Type = void>
using enable_if_t = typename enable_if<Condition, Type>::type;
```

## Usage Examples

### Example 1: Function Overloading with `std::enable_if`

```cpp
#include <iostream>
#include <type_traits>

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
```

### Example 2: Using `std::enable_if_t` for Simplicity

```cpp
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
```

### Example 3: SFINAE with Class Templates

```cpp
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
```

## Conclusion

`std::enable_if` and `std::enable_if_t` are essential tools for C++ template metaprogramming, allowing developers to conditionally enable or disable function templates and class template specializations based on compile-time type traits. This capability is crucial for writing generic and type-safe code. By understanding and utilizing `std::enable_if` and `std::enable_if_t`, you can create more flexible and robust C++ programs.
