#include <iostream>
#include <functional> // std::hash
#include <string>

// Custom type
struct Person {
    std::string name;
    int age;

    // Overload the == operator for comparison
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Specialize std::hash for the custom type
namespace std {
    template <>
    struct hash<Person> {
        std::size_t operator()(const Person& person) const {
            std::hash<std::string> hash_fn_str;
            std::hash<int> hash_fn_int;

            // Combine hash values using bitwise XOR and bit shifting
            return hash_fn_str(person.name) ^ (hash_fn_int(person.age) << 1);
        }
    };
}

int main() {
    Person p{"John Doe", 30};
    std::hash<Person> hash_fn;

    std::size_t hash_value = hash_fn(p);
    std::cout << "Hash value of Person is: " << hash_value << std::endl;

    std::unordered_map<std::string, int> word_count;

    word_count["hello"] = 1;
    word_count["world"] = 2;

    std::cout << "Count of 'hello': " << word_count["hello"] << std::endl;
    std::cout << "Count of 'world': " << word_count["world"] << std::endl;

    return 0;
}
