#include <cstdio>

// Forward declare the example function
void example(void);

void main() {
    example();



label1:
    printf("label1\n");
label2:
    printf("label2\n");

        goto label2;
}

void example() {
    int i = 0;
start:
    if (i < 10) {
        i++;
        goto start;
    }
}
