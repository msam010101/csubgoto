/*****************************************************************************
 * 
 * goto from one plain code block to another, with variable scope check
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    int var1 = 10; // Variable outside the first block
    std::cout << "Valid goto test 9 - checkpoint" << std::endl;

    {
        int var1 = 42; // Local to this block, shadows outer 'var1'
        std::cout << "Valid goto test 9 - checkpoint" << std::endl;

        if (a == 0) {
            goto second_block; // Jump to second block
        }

        std::cout << "Valid goto test 9 - checkpoint" << std::endl;
    }

    std::cout << "Valid goto test 9 - checkpoint" << std::endl;

    return ret;

second_block:
    {
        int var2 = 84; // Local to second block
        std::cout << "Valid goto test 9 - checkpoint" << std::endl;

        // Jump back to first block
        goto first_block_exit;
    }

first_block_exit:
    std::cout << "Valid goto test 9 - checkpoint" << std::endl;
    return ret;
}

int main() {
    std::cout << "Valid goto test 9 - start" << std::endl;

    // Test case with a = 0, triggering the goto between blocks
    int ret = func(0);
    if (0 != ret) {
        return ret;
    }

    // Test case with a = 1, no goto
    ret = func(1);
    std::cout << "Valid goto test 9 - end" << std::endl;
    return ret;
}
