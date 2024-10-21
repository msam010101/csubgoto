/*****************************************************************************
 * 
 * Valid goto test 11: Two `goto` and two labels in different scopes
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    std::cout << "Valid goto test 11 - checkpoint" << std::endl;

    // First `goto` inside a `for` loop
    for (int i = 0; i < 5; i++) {
        if (i == a) {
            goto label1; // Jump to label1 outside of the `for` loop
        }
        std::cout << "Valid goto test 11 - checkpoint" << std::endl;
    }

    // First label after the `for` loop
label1:
    std::cout << "Valid goto test 11 - checkpoint" << std::endl;

    // Second `goto` inside a `switch` statement
    switch (a) {
        case 1:
            std::cout << "Valid goto test 11 - checkpoint" << std::endl;
            goto label2; // Jump to label2 outside of the `switch`
        case 2:
            std::cout << "Valid goto test 11 - checkpoint" << std::endl;
            break;
        default:
            std::cout << "Valid goto test 11 - checkpoint" << std::endl;
            break;
    }

    // Second label after the `switch` statement
label2:
    std::cout << "Valid goto test 11 - checkpoint" << std::endl;

    return 0;
}

int main() {
    std::cout << "Valid goto test 11 - start" << std::endl;

    // Test with `a = 0`, no `goto` triggered in `switch`
    int ret = func(0);
    if (0 != ret) {
        return ret;
    }

    // Test with `a = 1`, triggers `goto` in both `for` and `switch`
    ret = func(1);
    std::cout << "Valid goto test 11 - end" << std::endl;
    return ret;
}
