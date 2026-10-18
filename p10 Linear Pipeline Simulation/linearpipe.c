#include <stdio.h>

int main() {
    int s, n, i, j, k;

    printf("Enter number of stages: ");
    scanf("%d", &s);
    printf("Enter number of instructions: ");
    scanf("%d", &n);

    printf("\nLinear Pipeline Simulation\n");
    for (i = 1; i <= n + s - 1; i++) {
        for (j = 1; j <= s; j++) {
            k = i - j + 1;
            if (k >= 1 && k <= n) {
                printf(" I%d ", k);
            } else {
                printf(" -  ");
            }
        }
        printf("\n");
    }

    printf("Total clock cycles = %d\n", n + s - 1);

    return 0;
}