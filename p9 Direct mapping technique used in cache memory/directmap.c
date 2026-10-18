
#include <stdio.h>

int main() {
    int cacheLines, blocks;
    int i, line;

    printf("Enter number of cache lines: ");
    scanf("%d", &cacheLines);

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    if (cacheLines <= 0 || blocks < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nDirect Mapping:\n");

    for (i = 0; i < blocks; i++) {
        line = i % cacheLines;
        printf("Memory Block %d -> Cache Line %d\n", i, line);
    }

    return 0;
}
