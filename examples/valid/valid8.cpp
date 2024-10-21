/*****************************************************************************
 * 
 * goto in function and plain code block with variable scope check
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    int var = 35; // Variable outside the block
    std::cout << "Valid goto test 8 - checkpoint" << std::endl;

    {
        int var = 42; // Local to this block, shadows outer 'var'
        if (a == 0) {
            goto label1; // Jump outside the block
            ret = -1;
        }
        std::cout << "Valid goto test 8 - checkpoint" << std::endl;
    }

    // Check that the outer 'var' retains its original value
    if (var != 35) {
        std::cout << "Valid goto test 8 - checkpoint" << std::endl;
        return -1;
    }

    std::cout << "Valid goto test 8 - checkpoint" << std::endl;
    return ret;

label1:
    std::cout << "Valid goto test 8 - checkpoint" << std::endl;
    return ret;
}

int main() {
    std::cout << "Valid goto test 8 - start" << std::endl;

    // Test case with a = 0, triggering the goto inside the plain code block
    int ret = func(0);
    if (0 != ret) {
        return ret;
    }

    // Test case with a = 1, no goto
    ret = func(1);
    std::cout << "Valid goto test 8 - end" << std::endl;
    return ret;
}
