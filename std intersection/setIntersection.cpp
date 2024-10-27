#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

struct Person {
    std::string name;
    int age;

    // Define equality operator for comparing two Person objects
    bool operator<(const Person& other) const {
        return name < other.name; // Sort based on name
    }
};

// Function to print a set of integers
void printSet(const std::set<int>& s) {
    for (const int& val : s) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Function to print a list of Person objects
void printPeople(const std::list<Person>& people) {
    for (const auto& person : people) {
        std::cout << person.name << " (" << person.age << ") ";
    }
    std::cout << std::endl;
}

void example1() {
    std::cout << "Example 1: Intersection of Sets (Integers)\n";
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {3, 4, 5, 6, 7};
    std::set<int> intersection;

    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(intersection, intersection.begin()));

    std::cout << "Intersection: ";
    printSet(intersection); // Expected output: 3 4 5
    std::cout << "\n";
}

void example2() {
    std::cout << "Example 2: Intersection of Lists (Strings)\n";
    std::list<std::string> list1 = {"apple", "banana", "cherry", "date"};
    std::list<std::string> list2 = {"cherry", "date", "fig", "grape"};
    std::list<std::string> intersection;

    std::set_intersection(list1.begin(), list1.end(),
                          list2.begin(), list2.end(),
                          std::back_inserter(intersection));

    std::cout << "Intersection: ";
    for (const auto& fruit : intersection) {
        std::cout << fruit << " "; // Expected output: cherry date
    }
    std::cout << "\n\n";
}

void example3() {
    std::cout << "Example 3: Intersection of Custom Structs\n";
    std::set<Person> people1 = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    std::set<Person> people2 = {{"Bob", 25}, {"David", 40}, {"Alice", 30}};
    std::set<Person> intersection;

    std::set_intersection(people1.begin(), people1.end(),
                          people2.begin(), people2.end(),
                          std::inserter(intersection, intersection.begin()));

    std::cout << "Intersection: ";
    for (const auto& person : intersection) {
        std::cout << person.name << " (" << person.age << ") "; // Expected output: Bob (25) Alice (30) 
    }
    std::cout << "\n\n";
}

void example4() {
    std::cout << "Example 4: Intersection with Different Container Types\n";
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::set<int> set1 = {4, 5, 6, 7, 8};
    std::vector<int> intersection;

    std::set_intersection(vec1.begin(), vec1.end(),
                          set1.begin(), set1.end(),
                          std::back_inserter(intersection));

    std::cout << "Intersection: ";
    for (int val : intersection) {
        std::cout << val << " "; // Expected output: 4 5
    }
    std::cout << "\n\n";
}

int main() {
    example1();
    example2();
    example3();
    example4();

    return 0;
}
