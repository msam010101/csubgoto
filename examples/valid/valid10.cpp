/*****************************************************************************
 * 
 * goto from one plain code block to a nested plain code block,
 * with variable scope check (no print statements)
 * 
 *****************************************************************************/

#include <iostream>

int func(int a) {
    int ret = 0;
    int var1 = 10; // Variable outside the first block

    // Outer block
    {
        int var1 = 42; // Local to this block, shadows outer 'var1'

        if (0 == a) {
            goto nested_block; // Jump to the nested block
        }

        // If `goto` didn't trigger, but the function is continuing here, return -1
        if (a == 0) {
            return -1;
        }

        // Nested block within the outer block
        {
        nested_block:
            int var2 = 84; // Local to the nested block

            // Check that `goto` worked correctly
            if (a == 0 && var1 != 42) {
                return -1;
            }

            if (1 == a) {
                goto exit_nested_block; // Exit the nested block
            }
        }

    exit_nested_block:
        // Check that outer 'var1' is still 42 after exiting the nested block
        if (var1 != 42) {
            return -1;
        }
    }

    // Check that the outermost 'var1' retains its original value (10)
    if (var1 != 10) {
        return -1;
    }

    return ret;
}

int main() {
    std::cout << "Valid goto test 10 - start" << std::endl;

    // Test case with a = 0, triggering the goto into the nested block
    int ret = func(0);
    if (0 != ret) {
        return ret;
    }

    // Test case with a = 1, triggering the goto out of the nested block
    ret = func(1);
    std::cout << "Valid goto test 10 - end" << std::endl;
    return ret;
}
