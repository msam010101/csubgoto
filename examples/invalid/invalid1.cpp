/*****************************************************************************
 * 
 * no goto
 * 
 *****************************************************************************/

#include <iostream>

int func(void) {
label1:
    return 0;
}

int main() {
    std::cout << "Valid goto test 1 - start" << std::endl;
    std::cout << "Valid goto test 1 - end" << std::endl;

    goto label1;
    return 0;
}
