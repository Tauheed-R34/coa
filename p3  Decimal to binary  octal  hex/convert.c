#include <stdio.h>

int main() {
    int n, base, r, i = 0;
    char result[50];

    printf("Enter decimal number: ");
    scanf("%d", &n);

    printf("Enter base (2, 8, 16): ");
    scanf("%d", &base);

    if (n == 0) {
        printf("Result = 0\n");
        return 0;
    }

    while (n > 0) {
        r = n % base;

        if (r < 10)
            result[i] = r + '0';
        else
            result[i] = r - 10 + 'A';

        i++;
        n = n / base;
    }

    printf("Result = ");

    for (i = i - 1; i >= 0; i--)
        printf("%c", result[i]);

    printf("\n");
    return 0;
}