
#include <stdio.h>

int main() {
    double S[2], C[2], T[2], H[2];
    double total_cost = 0, total_size = 0;
    double avg_cost, avg_access_time;

    printf("Analysis of Memory Hierarchy (2-Level)\n");

    for (int i = 0; i < 2; i++) {
        printf("\nLevel %d\n", i + 1);

        printf("Size: ");
        scanf("%lf", &S[i]);

        printf("Cost/bit: ");
        scanf("%lf", &C[i]);

        printf("Access time: ");
        scanf("%lf", &T[i]);

        printf("Hit rate/ratio: ");
        scanf("%lf", &H[i]);

        total_cost += C[i] * S[i];
        total_size += S[i];
    }

    avg_cost = total_cost / total_size;
    avg_access_time = H[0] * T[0]
                    + (1 - H[0]) * T[1];

    printf("\nAverage cost/bit = %.6f\n", avg_cost);
    printf("Average access time = %.4f microseconds\n",
           avg_access_time);

    return 0;
}
