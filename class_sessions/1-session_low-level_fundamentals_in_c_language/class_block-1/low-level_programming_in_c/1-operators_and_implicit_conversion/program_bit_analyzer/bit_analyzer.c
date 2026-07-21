// #================================================================================================#
// # Write a program that takes a number between 0 and 255 (define it as a constant in the code     #
// # no keyboard input needed yet) and shows a complete analysis of that byte.                      #
// #                                                                                                #
// # It must show :                                                                                 # 
// #                                                                                                # 
// # * The value in decimal                                                                         #
// # * The value in hexadecimal                                                                     # 
// # * The value interpreted as signed                                                              #
// # * The value interpreted as unsigned                                                            #
// # * Whether the number is even or odd                                                            #
// # * How many bits are on (at 1) in the byte                                                      #
// #                                                                                                # 
// #================================================================================================# 


#include <stdio.h>

int main() {
	
printf("\n");
printf("#======================================#\n");
printf("#=====|  WELCOME TO BIT ANALYZER |=====#\n");
printf("#======================================#\n");
printf("\n");

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 1. Declare two variables in constant format, one that stores the total value with sign                          |
//|  and then store the other one doing truncation to avoid signed extension when storing the value in signed char  |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  

unsigned int valor = 200;
signed char valor_signo = valor;

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 2. Use a for loop, declare i at size 7 to show only the 8 low bits of the value, while i keeps being            |
//+  greater than 0 or until it equals 0, decrement i by 1 each time, shift a variable that performs the operation  +
//|   of moving the value of the $valor variable at bit level, then capture the bit at its current position         |
//+     isolating it with the & (AND) operator, and finally print to screen on each loop iteration to form the      +
//|     value in binary format.                                                                                     |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("========================================\n");
printf("* THE VALUE INTERPRETED AS BINARY\n");
printf("----------------------------------------\n");
printf("BINARY : ");

for (int i = 7; i >= 0; i--){
	
	int bit = (valor >> i) &1;	
        printf("%d", bit);
	
	}	

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 3. Print to screen the value of the unsigned variable in decimal format                                         |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 
printf("\n========================================\n");
printf("----------------------------------------\n");
printf("* THE VALUE INTERPRETED AS DECIMAL\n");
printf("DECIMAL : %u\n", valor);

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 4. Take the variable with unsigned value and divide it with the modulo operator then compare the result         |
//|  with 0, if the result equals 0 show as even number and if it is different from 0 show as odd.                  |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// since the variable is specifically 32-bit there are no problems from implicit conversion or signed extension.

printf("========================================\n");
printf("----------------------------------------\n");
int divisor = valor % 2;

 if (divisor == 0){
	 printf("* THE VALUE: %d IS AN EVEN NUMBER\n", valor);
 	          }  else {
			printf("* THE VALUE: %d IS AN ODD NUMBER\n", valor);
			}	 

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 5. Print to screen the unsigned value interpreted as a hexadecimal number                                       |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("========================================\n");
printf("* THE VALUE INTERPRETED AS HEX NUMBER\n");
printf("----------------------------------------\n");
printf("HEXADECIMAL : 0x%X\n", valor);

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 6. Truncate the value of the unsigned variable into a smaller signed variable and then print to screen          |
//|  the value of that signed variable                                                                              | 
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("========================================\n");
printf("* THE VALUE INTERPRETED AS SIGNED \n");
printf("----------------------------------------\n");
printf("SIGNED : %d\n", valor_signo);

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 7. Take the same logic from step 2, modify the loop, instead of printing to screen, capture the bits            | 
//+   that are on, store them in an array, then count the size and print to screen the number of bits on            +
//|                                                                                                                 |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

return 0;

}
