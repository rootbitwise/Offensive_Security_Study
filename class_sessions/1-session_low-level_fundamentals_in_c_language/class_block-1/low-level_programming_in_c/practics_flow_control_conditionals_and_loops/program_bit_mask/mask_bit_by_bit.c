#include<stdio.h>
#include<stdint.h>

int main(void)
{

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Declare two variables, one unsigned of specific size 32-bits            |
// + another signed of specific size 32-bits.                                +
// | both with the same decimal value.                                       |  
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	 
int32_t var_signed = -32;
uint32_t var_unsigned = var_signed; // 4 billion by implicit assignment

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Two for loops that do exactly the same thing, first they count down     |
// + from 31 to 0, as long as the variable is greater than or equal to 0     +
// | it decreases the variable by 1.                                         |
// +                                                                         +
// | body:                                                                   |
// + ------------------------------------------------------------------------+
// | a variable that moves n positions to the left and isolates only the     |
// + bit at the position it is currently at and then prints to screen        +
// | that specific bit, to show the value in binary format                   |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("-----------------------------------\n");
printf("| SHOW EACH BIT OF THE VARIABLE   |\n");
printf("-----------------------------------\n");
	
for (int i = 31; i >= 0; i--)
{
 	int32_t bit = (var_signed >> i)&1;
	printf("%d", bit);
}	

printf("\n");
printf("-----------------------------------\n");
printf("|    SHOW DECIMAL OF SIGNED       |\n");
printf("-----------------------------------\n");		
printf("%d\n", var_signed);
	
printf("-----------------------------------\n");
printf("| SHOW THE BITS OF VAR_UNSIGNED   |\n");
printf("-----------------------------------\n");

for (int i = 31; i >= 0; i--)
{
	uint32_t bit_unsigned = (var_unsigned >> i)&1;
	printf("%u", bit_unsigned);
}	

printf("\n");
printf("-----------------------------------\n");
printf("| SHOW THE DECIMAL OF UNSIGNED    |\n");
printf("-----------------------------------\n");
printf("%u",var_unsigned);
printf("\n");

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Use a mask with NOT to turn off the 32-bits of var_unsigned             |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("-----------------------------------\n");
printf("| INVERT THE BITS OF VAR_UNSIGNED |\n");
printf("-----------------------------------\n");

for (int i = 31; i >= 0; i--)
{
	uint32_t bits = (var_unsigned >> i) &1;
	uint32_t not_bits = ~bits &1;	
	printf("%u",not_bits);
}
	
	return 0;
}
