#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void)
{
    printf("==========================================\n");

    printf("char:           %lu byte(s)\n", sizeof(char));
    printf("short:          %lu byte(s)\n", sizeof(short));
    printf("int:            %lu byte(s)\n", sizeof(int));
    printf("long:           %lu byte(s)\n", sizeof(long));
    printf("long long:      %lu byte(s)\n", sizeof(long long));
    printf("float:          %lu byte(s)\n", sizeof(float));
    printf("double:         %lu byte(s)\n", sizeof(double));
    printf("int *:          %lu byte(s)\n", sizeof(int *));

    printf("\n===  (stdint.h) ===\n\n");

    printf("int8_t:         %lu byte(s)\n", sizeof(int8_t));
    printf("int16_t:        %lu byte(s)\n", sizeof(int16_t));
    printf("int32_t:        %lu byte(s)\n", sizeof(int32_t));
    printf("int64_t:        %lu byte(s)\n", sizeof(int64_t));

    printf("\n=== Rangos signed ===\n\n");

    printf("CHAR_MIN:       %d\n", CHAR_MIN);
    printf("CHAR_MAX:       %d\n", CHAR_MAX);
    printf("SHRT_MIN:       %d\n", SHRT_MIN);
    printf("SHRT_MAX:       %d\n", SHRT_MAX);
    printf("INT_MIN:        %d\n", INT_MIN);
    printf("INT_MAX:        %d\n", INT_MAX);
    printf("LONG_MIN:       %ld\n", LONG_MIN);
    printf("LONG_MAX:       %ld\n", LONG_MAX);

    printf("\n=== Range unsigned ===\n\n");

    printf("UCHAR_MAX:      %u\n", UCHAR_MAX);
    printf("USHRT_MAX:      %u\n", USHRT_MAX);
    printf("UINT_MAX:       %u\n", UINT_MAX);
    printf("ULONG_MAX:      %lu\n", ULONG_MAX);

    return 0;
}
