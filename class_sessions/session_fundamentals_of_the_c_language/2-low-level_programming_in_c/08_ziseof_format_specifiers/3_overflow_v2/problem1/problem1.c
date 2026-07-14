#include <stdio.h>

int main(void){


	printf("\nthe data 200 would be interpreted as -56 because if a character is signed, its range is -128 to +127.\n 200 in binary doesn't fit within that range, so its make jump, and number that printf interprets is -56 because %%d also prints signed decimal numbers\n");  

	printf("=============\n");
	char x = 200;
	printf("x = %d", x);

return 0;

}
