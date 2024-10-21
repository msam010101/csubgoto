/*****************************************************************************
 * 
 * goto in function and while statement with variable scope check
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    int counter = 10; // Variable outside the while loop
    std::cout << "Valid goto test 5 - checkpoint" << std::endl;

    while (counter < 15) {
        int inner_counter = 0; // Local to the while loop, shadows outer 'counter'
        if (inner_counter == a) {
            goto label1; // Jump outside the while loop
            ret = -1;
        }

        std::cout << "Valid goto test 5 - checkpoint" << std::endl;
        counter++; // Increment counter to avoid infinite loop
    }

    // Check that the outer 'counter' retains its original value
    if (counter != 15) {
        std::cout << "Valid goto test 5 - checkpoint" << std::endl;
        return -1;
    }

    std::cout << "Valid goto test 5 - checkpoint" << std::endl;
    return ret;

label1:
    std::cout << "Valid goto test 5 - checkpoint" << std::endl;
    return ret;
}

int main() {
    std::cout << "Valid goto test 5 - start" << std::endl;

    // Test case with a = 0, triggering the goto inside while
    int ret = func(0);
    if (0 != ret) {
        return ret;
    }

    // Test case with a = 6, no goto
    ret = func(6);
    std::cout << "Valid goto test 5 - end" << std::endl;
    return ret;
}
