/*****************************************************************************
 * 
 * goto in function
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    volatile int ret = 0;
    std::cout << "Valid goto test 2 - checkpoint" << std::endl;

    if (0 == a) {
        goto label1;
        ret = -1;
    }

    std::cout << "Valid goto test 2 - checkpoint" << std::endl;
    return ret;

label1:
    std::cout << "Valid goto test 2 - checkpoint" << std::endl;

    return ret;
}

int main() {
    volatile int ret;

    std::cout << "Valid goto test 2 - start" << std::endl;
    
    ret = func(0);
    if (0 != ret) {
        return ret;
    }
    ret = func(1);

    std::cout << "Valid goto test 2 - end" << std::endl;

    return ret;
}
