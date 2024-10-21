/*****************************************************************************
 * 
 * goto in main
 * 
 *****************************************************************************/

#include <iostream>

int main() {
    volatile int a = 0;
    std::cout << "Valid goto test 3 - start" << std::endl;

    if (0 == a) {
        goto label1;
    }

    std::cout << "Valid goto test 3 - checkpoint" << std::endl;
    return -1;

label1:
    std::cout << "Valid goto test 3 - end" << std::endl;

    return 0;
}
