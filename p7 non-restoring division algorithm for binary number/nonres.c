#include <stdio.h>

#define N 8

void printBinary(int num, int bits) {
    int i;

    for (i = bits - 1; i >= 0; i--)
        printf("%d", (num >> i) & 1);
}

int main() {
    int dividend, divisor;
    int A = 0, Q, M, count = N;
    int mask = (1 << N) - 1;
    int Asigned, Afinal;

    printf("Enter dividend in decimal = ");
    scanf("%d", &dividend);

    printf("Enter divisor in decimal = ");
    scanf("%d", &divisor);

    if (dividend < 0 || dividend > 255 ||
        divisor <= 0 || divisor > 127) {
        printf("Invalid input.\n");
        return 0;
    }

    Q = dividend & mask;
    M = divisor & mask;

    printf("\nDividend in binary = ");
    printBinary(Q, N);

    printf("\nDivisor in binary = ");
    printBinary(M, N);

    while (count-- > 0) {
        A = ((A << 1) | ((Q >> (N - 1)) & 1)) & mask;
        Q = (Q << 1) & mask;

        Asigned = (A << (32 - N)) >> (32 - N);

        if (Asigned >= 0)
            Asigned -= M;
        else
            Asigned += M;

        A = Asigned & mask;

        if (Asigned >= 0)
            Q |= 1;
        else
            Q &= ~1;
    }

    Afinal = (A << (32 - N)) >> (32 - N);

    if (Afinal < 0)
        Afinal += M;

    A = Afinal & mask;

    printf("\n\nQuotient in binary = ");
    printBinary(Q, N);

    printf("\nRemainder in binary = ");
    printBinary(A, N);

    printf("\n\nQuotient in decimal = %d", Q);
    printf("\nRemainder in decimal = %d\n", A);

    return 0;
}