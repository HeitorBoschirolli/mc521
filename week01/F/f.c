#include <stdio.h>
#include <malloc.h>

int main() {
    int j, r;
    int *parciais;
    int temp;
    int max;
    int max_id;

    scanf("%d %d", &j, &r);

    parciais = (int *)(malloc(r * sizeof(int)));

    for (int a = 0; a < j; a++) {
        parciais[a] = 0;
    }

    for (int a = 0; a < r; a++) {
        for (int b = 0; b < j; b++) {
            scanf("%d", &temp);
            parciais[b] += temp;
        }
    }

    max = parciais[0];
    max_id = 0;
    for (int a = 1; a < j; a++) {
        if (parciais[a] >= max) {
            max = parciais[a];
            max_id = a;
        }

    }

    printf("%d\n", max_id + 1);

    return 0;
}
