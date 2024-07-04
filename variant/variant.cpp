#include <variant>
#include <iostream>
#include <string>

// Define a visitor struct for std::visit
struct PrintVisitor {
    void operator()(int value) const {
        std::cout << "Stored value is an int: " << value << std::endl;
    }
    
    void operator()(double value) const {
        std::cout << "Stored value is a double: " << value << std::endl;
    }
    
    void operator()(const std::string& value) const {
        std::cout << "Stored value is a string: " << value << std::endl;
    }
};

int main() {
    // Example of using std::variant, std::get, std::get_if, std::holds_alternative, and std::visit
    std::variant<int, double, std::string> var;
    
    var = 10; // Store an int
    
    // Accessing stored int value safely
    int value = std::get<int>(var);
    std::cout << "Stored value is an int: " << value << std::endl;
    
    // Changing stored type and accessing double value
    var = 3.14; // Now store a double
    double double_value = std::get<double>(var);
    std::cout << "Stored value is a double: " << double_value << std::endl;
    
    // Using std::get_if to safely access stored string value
    var = "Hello"; // Store a string
    if (auto str_ptr = std::get_if<std::string>(&var)) {
        std::cout << "Stored value is a string: " << *str_ptr << std::endl;
    } else {
        std::cout << "Stored value is not a string!" << std::endl;
    }
    
    // Using std::holds_alternative to check stored type and access safely
    var = 3.14; // Store a double again
    if (std::holds_alternative<double>(var)) {
        double value = std::get<double>(var);
        std::cout << "Stored value is a double: " << value << std::endl;
    } else {
        std::cout << "Stored value is not a double!" << std::endl;
    }
    
    // Using std::visit with a visitor to print stored value
    var = "Hello"; // Store a string again
    std::visit(PrintVisitor{}, var);
    
    return 0;
}
