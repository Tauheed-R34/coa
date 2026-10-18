
#include <stdio.h>

#define N 8

void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int dividend, divisor;
    int A = 0, Q, M, count = N;
    int mask = (1 << N) - 1;

    printf("Enter dividend in decimal = ");
    scanf("%d", &dividend);

    printf("Enter divisor in decimal  = ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Division by zero is not allowed.\n");
        return 1;
    }

    if (dividend < 0 || dividend > 255 ||
        divisor < 0 || divisor > 255) {
        printf("Enter values between 0 and 255.\n");
        return 1;
    }

    Q = dividend;
    M = divisor;

    printf("\nDividend in binary = ");
    printBinary(Q, N);

    printf("\nDivisor in binary  = ");
    printBinary(M, N);

    while (count > 0) {
        A = ((A << 1) | ((Q >> (N - 1)) & 1));
        Q = (Q << 1) & mask;

        A = A - M;

        if (A < 0) {
            A = A + M;
            Q = Q & ~1;
        } else {
            Q = Q | 1;
        }

        count--;
    }

    printf("\n\nQuotient in binary  = ");
    printBinary(Q, N);

    printf("\nRemainder in binary = ");
    printBinary(A, N);

    printf("\n\nQuotient in decimal  = %d", Q);
    printf("\nRemainder in decimal = %d\n", A);

    return 0;
}
