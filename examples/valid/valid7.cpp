/*****************************************************************************
 * 
 * goto in function and for statement with variable scope check
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    int i = 10; // Variable outside the for loop
    std::cout << "Valid goto test 7 - checkpoint" << std::endl;

    for (int i = 0; i < 5; i++) {  // 'i' local to the for loop, shadows outer 'i'
        if (i == a) {
            goto label1; // Jump outside the for loop
            ret = -1;
        }

        std::cout << "Valid goto test 7 - checkpoint" << std::endl;
    }

    // Check that the outer 'i' retains its original value
    if (i != 10) {
        std::cout << "Valid goto test 7 - checkpoint" << std::endl;
        return -1;
    }

    std::cout << "Valid goto test 7 - checkpoint" << std::endl;
    return ret;

label1:
    std::cout << "Valid goto test 7 - checkpoint" << std::endl;
    return ret;
}

int main() {
    std::cout << "Valid goto test 7 - start" << std::endl;

    // Test case with a = 2, triggering the goto inside for loop
    int ret = func(2);
    if (0 != ret) {
        return ret;
    }

    // Test case with a = 6, no goto
    ret = func(6);
    std::cout << "Valid goto test 7 - end" << std::endl;
    return ret;
}
