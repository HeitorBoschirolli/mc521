#include <stdio.h>
#include <math.h>

int main() {
    long int num;
    int pode = 0;
    scanf("%ld", &num);

    for (long int i = 2; i < sqrt(num); i++) {
        if (num % i == 0)
            pode = 1;
    }

    if (pode == 1)
        printf("S\n");
    else
        printf("N\n");
}
