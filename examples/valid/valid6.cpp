/*****************************************************************************
 * 
 * goto in function and do-while statement with variable scope check
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    int counter = 10; // Variable outside the do-while loop
    std::cout << "Valid goto test 6 - checkpoint" << std::endl;

    do {
        int counter = 0; // Local to the do-while loop, shadows outer 'counter'
        if (counter == a) {
            goto label1; // Jump outside the do-while loop
            ret = -1;
        }

        std::cout << "Valid goto test 6 - checkpoint" << std::endl;
        counter++;
    } while (counter < 5);

    // Check that the outer 'counter' retains its original value
    if (counter != 10) {
        std::cout << "Valid goto test 6 - checkpoint" << std::endl;
        return -1;
    }

    std::cout << "Valid goto test 6 - checkpoint" << std::endl;
    return ret;

label1:
    std::cout << "Valid goto test 6 - checkpoint" << std::endl;
    return ret;
}

int main() {
    std::cout << "Valid goto test 6 - start" << std::endl;

    // Test case with a = 2, triggering the goto inside do-while
    int ret = func(2);
    if (0 != ret) {
        return ret;
    }

    // Test case with a = 6, no goto
    ret = func(6);
    std::cout << "Valid goto test 6 - end" << std::endl;
    return ret;
}
