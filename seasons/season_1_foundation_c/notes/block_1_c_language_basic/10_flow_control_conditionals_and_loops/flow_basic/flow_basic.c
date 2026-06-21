// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | 1. A for that prints the numbers from 1 to 20.                            |
// + * If the number is a multiple of 3, print fizz instead of the number      +
// | * If the number is a multiple of 5, print buzz                            |
// + * If the number is a multiple of both (15), print fizzbuzz                +
// | * Otherwise, print the number.                                            |
// +                                                                           +
// |  2. A while that counts backward from 10 to 0                             |
// +                                                                           +
// |  3. A switch that takes a number from 1 to 7 (constant in the code) and   |
// +   prints the corresponding day of the week.                               +
// |                                                                           |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#include <stdio.h>
int main(void){
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | 1. Make two variables that store the result of dividing i by 3 and the    |
// +   other by 5                                                              +
// | 2. Make another variable that adds the result of both variables.          |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
printf("=================================\n");
printf("| FLOW BASIC, FIZZBUZZ PROGRAM  |\n");
printf("=================================\n");
	for (int i = 1; i <= 20; i++){
	
	// code variables.
	
	int jump3 = i % 3;
	int jump5 = i % 5;	
	int jumping = jump5 + jump3;
	
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | 1. compare the result of adding the remainder of dividing 3 by the        |
// +   value of i and dividing 5 by i, and if the result is 0 then             +
// |     print fizzbuzz, to say that it is a multiple of 15.                   |
// +                                                                           +
// | 2. compare the division between the value of i and 3, if the result is 0  |
// +    print fizz                                                             +
// |                                                                           |
// + 3. compare the division between the value of i and 5, if the result is 0  +
// |    print buzz                                                             |
// +                                                                           + 
// | 4. if the number is not a multiple of 3 or 5 then print the value of i    |        
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
		if (jumping == 0)
		{
			// if jumping equals 0 print fizzbuzz
			printf("fizzbuzz\n");
		}
		else if (jump3 == 0)
		{
			// If jump3 equals 0 then print fizz
			printf("fizz\n");
		}
		else if (jump5 == 0 )
		{	
			// If jump5 equals 0 then print buzz 
			printf("buzz\n");
		}
		else 
		{
			printf("%d\n", i);
		}
  }
 
printf("================\n");
	int y = 10; 
//prints a countdown from 10 to 0
 
	while (y >= 0)
	{
		printf("%d\n",y);
		y--;
	} 
printf("================\n");
	for (int d = 1; d <= 7; d++)
	{
		switch(d)
		{
			case 1: 
				printf("Today is Monday\n");
				printf("-----------------\n");
			break;
			case 2: 
				printf("Today is Tuesday\n");
				printf("-----------------\n");
			break;
			case 3:
		        	printf("Today is Wednesday\n");
				printf("-----------------\n");
			break;
			case 4:
				printf("Today is Thursday\n");
				printf("-----------------\n");
			break;
			case 5:
				printf("Today is Friday\n");
				printf("-----------------\n");
			
			break;
			case 6:
				printf("Today is Saturday\n");
				printf("-----------------\n");
			break;
			case 7: 
				printf("Today is Sunday\n");
				printf("-----------------\n");
			break;	
		}
	}
return 0;
}
