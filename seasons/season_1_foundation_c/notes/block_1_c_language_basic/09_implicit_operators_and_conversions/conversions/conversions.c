#include <stdio.h>

int main(void)
{
    printf("=== int vs double ===\n\n");
    printf("7 / 2     = %d\n", 7 / 2);
    printf("7 %% 2     = %d\n", 7 % 2);
    printf("7 / 2.0   = %f\n", 7 / 2.0);
    printf("7.0 / 2   = %f\n", 7.0 / 2);

    printf("\n=== Signed + unsigned ===\n\n");
    unsigned int u = 10;
    int s = -20;
    printf("u = 10, s = -20\n");
    printf("u + s (how %%d) = %d\n", u + s);
    printf("u + s (how %%u) = %u\n", u + s);

    printf("\n=== signed vs unsigned ===\n\n");
    int x = -1;
    unsigned int y = 1;
    if (x > y) {
        printf("-1 > 1 is True (implicit conversion)\n");
    } else {
        printf("-1 > 1 is False\n");
    }

    return 0;
}

