/*****************************************************************************
 * 
 * goto in function and switch statement with variable scope check
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    volatile int switch_var = 10;
    std::cout << "Valid goto test 4 - checkpoint" << std::endl;

    switch (a) {
        case 0: {
            volatile int switch_var = 42;
            goto label1;
            ret = -1;
            break;
        }

        case 1:
            std::cout << "Valid goto test 4 - checkpoint" << std::endl;
            break;

        default:
            std::cout << "Valid goto test 4 - checkpoint" << std::endl;
            break;
    }

    if (switch_var != 10) {
        std::cout << "Valid goto test 4 - checkpoint" << std::endl;
        return -1;
    }

    std::cout << "Valid goto test 4 - checkpoint" << std::endl;
    return ret;

label1:
    std::cout << "Valid goto test 4 - checkpoint" << std::endl;
    return ret;
}

int main() {
    volatile int ret;
    std::cout << "Valid goto test 4 - start" << std::endl;
    
    ret = func(0);
    if (0 != ret) {
        return ret;
    }

    ret = func(1);
    std::cout << "Valid goto test 4 - end" << std::endl;
    return ret;
}
