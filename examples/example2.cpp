#include <iostream>

// Simple function with no parameters and a void return type
void simpleFunction() {
    std::cout << "This is a simple function." << std::endl;
}

// Function with parameters and an integer return type
int addNumbers(int a, int b) {
    return a + b;
}

// Function with nested if-statements and loops
void complexFunction(int n) {
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                std::cout << "Even number: " << i << std::endl;
            } else {
                std::cout << "Odd number: " << i << std::endl;
            }
        }
    } else {
        std::cout << "Negative or zero." << std::endl;
    }
}

// Function with a more complex return type (pointer)
int* returnPointer(int& ref) {
    return &ref;
}

// Function with no return value, but deeply nested blocks
void nestedBlocks() {
    if (true) {
        while (false) {
            for (int i = 0; i < 10; i++) {
                if (i == 5) {
                    break;
                }
            }
        }
    }
}

// Function with no parameters, return type double
double getPi() {
    return 3.14159;
}

// Template function
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    simpleFunction();
    int sum = addNumbers(3, 4);
    std::cout << "Sum: " << sum << std::endl;

    complexFunction(5);
    
    int value = 10;
    int* ptr = returnPointer(value);
    std::cout << "Pointer value: " << *ptr << std::endl;

    nestedBlocks();
    double pi = getPi();
    std::cout << "Pi: " << pi << std::endl;

    std::cout << "Multiplying template function: " << multiply(2, 3) << std::endl;

    return 0;
}
