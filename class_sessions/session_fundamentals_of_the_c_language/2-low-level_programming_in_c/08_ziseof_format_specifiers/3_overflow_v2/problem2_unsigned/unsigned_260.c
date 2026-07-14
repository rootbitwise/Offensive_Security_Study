#include <stdio.h>

int main(void){
	
printf("\n Something similar to problem 1 would happen: the value doesn't fit, but since it's a unsigned value with a range of 0 to 255, the binary sum results in a value lower than expected. \n");

	unsigned char x = 250;
	unsigned char y = 10;
	unsigned char z = x + y;

	printf("\n unsigned char z = x (250) + y (10),the result of z = %u",z); 	

 return 0;


}
