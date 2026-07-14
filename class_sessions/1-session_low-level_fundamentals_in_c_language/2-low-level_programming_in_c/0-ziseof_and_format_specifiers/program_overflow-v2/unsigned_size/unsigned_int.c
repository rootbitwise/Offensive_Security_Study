#include <stdio.h>

int main(void)
{
    int value_signed = -1;
    unsigned int  value_unsigned = 4294967295U;

    printf("=== value_signed (-1) 3 format ===\n\n");
    printf("%%d  =  %d\n", value_signed);
    printf("%%u  =  %u\n", value_signed);
    printf("%%X  =  0x%X\n", value_signed);

    printf("\n=== value_unsigned (4294967295) 3 format ===\n\n");
    printf("%%d  =  %d\n", value_unsigned);
    printf("%%u  =  %u\n", value_unsigned);
    printf("%%X  =  0x%X\n", value_unsigned);

    return 0;
}
