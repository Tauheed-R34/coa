#include <stdio.h>

union FloatBits {
    float number;
    unsigned int binary;
};

int main() {
    union FloatBits fb;
    int i;

    printf("Enter a floating point number: ");
    scanf("%f", &fb.number);

    printf("Sign Bit = %u\n",
           (fb.binary >> 31) & 1U);

    printf("Exponent = ");
    for (i = 30; i >= 23; i--)
        printf("%u", (fb.binary >> i) & 1U);

    printf("\nMantissa = ");
    for (i = 22; i >= 0; i--)
        printf("%u", (fb.binary >> i) & 1U);

    printf("\nComplete IEEE 754 = ");
    for (i = 31; i >= 0; i--) {
        printf("%u", (fb.binary >> i) & 1U);

        if (i == 31 || i == 23)
            printf(" ");
    }

    printf("\n");
    return 0;
}