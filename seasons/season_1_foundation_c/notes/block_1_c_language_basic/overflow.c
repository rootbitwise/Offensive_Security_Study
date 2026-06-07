#include <stdio.h>

int main(void){


printf("\n");	
printf("Bitwise Overlow\n");

signed char num1 = -56;
signed char num2 = -100;

unsigned int result  = num1 + num2; 

printf("Overflow : char -56 + -100 : %u \n", result);


return 0;
}
