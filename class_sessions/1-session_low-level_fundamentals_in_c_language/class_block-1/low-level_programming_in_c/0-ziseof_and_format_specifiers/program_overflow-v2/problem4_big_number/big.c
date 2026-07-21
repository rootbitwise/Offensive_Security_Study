#include <stdio.h>
#include <stdint.h>

int main(void){


	int8_t a = 100;
	int8_t b = 50;

	int8_t sum = a + b;

	printf("sum a(100) + b(50)  is = %d\n",sum);

	uint32_t big = 0xDEADBEEF;

	printf("the value of big in unsigned is %u\n",big);
	printf("the value of big in hex is 0x%X\n",big);	

	return 0;


}
