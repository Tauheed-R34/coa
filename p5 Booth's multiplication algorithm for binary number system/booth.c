#include <stdio.h>

void printBinary(int num, int n) {
    int i;
    unsigned int mask = 1U << (n - 1);

    for (i = 0; i < n; i++) {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;
    }
}

int main() {
    int M, Q, n;
    int A = 0, Q_1 = 0;
    int count, Q0;
    int carryA, carryQ;

    printf("Enter Multiplicand (M): ");
    scanf("%d", &M);

    printf("Enter Multiplier (Q): ");
    scanf("%d", &Q);

    printf("Enter Number of Bits (n): ");
    scanf("%d", &n);

    if (n < 2 || n > 15) {
        printf("Enter bits between 2 and 15.\n");
        return 0;
    }

    count = n;

    printf("\nM in binary = ");
    printBinary(M, n);

    printf("\nQ in binary = ");
    printBinary(Q, n);

    printf("\n\n%-6s %-15s %-15s %-3s\n",
           "Step", "A", "Q", "Q-1");

    while (count > 0) {
        Q0 = Q & 1;

        if (Q0 == 0 && Q_1 == 1)
            A = A + M;
        else if (Q0 == 1 && Q_1 == 0)
            A = A - M;

        carryA = A & 1;
        carryQ = Q & 1;

        A = A >> 1;
        Q = (Q >> 1) & ~(1 << (n - 1));
        Q = Q | (carryA << (n - 1));
        Q_1 = carryQ;

        count--;

        printf("%-6d ", n - count);
        printBinary(A, n);
        printf(" ");
        printBinary(Q, n);
        printf(" %d\n", Q_1);
    }

    printf("\nResult (A Q) = ");
    printBinary(A, n);
    printBinary(Q, n);

    printf("\nProduct (decimal) = %d\n",
           A * (1 << n) + (Q & ((1 << n) - 1)));

    return 0;
}