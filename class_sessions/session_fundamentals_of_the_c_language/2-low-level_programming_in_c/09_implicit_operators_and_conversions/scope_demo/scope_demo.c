#include <stdio.h>

int main(void)
{
    int count = 5;

    int post = count++;
    int pre  = ++count;

    printf("count = %d\n", count);
    printf("post = %d\n", post);
    printf("pre = %d\n", pre);

    printf("\n");

    int x = 10;
    x += 5;
    x *= 2;
    x -= 3;
    x /= 4;

    printf("x = %d\n", x);

    return 0;
}
