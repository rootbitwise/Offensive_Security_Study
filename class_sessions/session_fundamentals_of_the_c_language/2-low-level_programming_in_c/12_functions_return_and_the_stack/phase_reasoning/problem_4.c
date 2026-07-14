#include <stdio.h>
int classify(int n)
{
if (n > 0)
    {
return 1;  // returns the value 1 to the printf in main
    }
if (n < 0)
    {
return -1; // returns the value -1 to the printf in main
    }
return 0; // returns the value 0 to the printf in main
}
int main(void){
printf("%d\n", classify(7)); // passes 7 as argument to the function then prints the value the function returns
printf("%d\n", classify(-3)); // passes -3 as argument to the function then prints the value it returns
printf("%d\n", classify(0)); // passes 0 as argument to the function then prints the value it returns
return 0;
}
/* The program first passes an argument to the function and then it is evaluated and if the evaluation is true
 * a numeric value is returned that main prints to screen.
 *
 * 1. classify(7) : the value 7 is passed as argument to the classify function, it says int n = 7
 * if 7 is greater than 0 it returns the value 1, this value goes to the printf in main who prints it to screen
 *
 * Then repeats : classify(-3) : -3 is passed as argument to the classify function, it says int n = -3
 * if -3 is less than 0 then it returns the numeric value -1, this value is passed to the printf in main
 * who prints it to screen
 *
 * then repeats : classify(0) passes 0 as argument to the classify function, it says int n = 0, then evaluates
 * if 0 is greater than 0 it returns 1, this is false it moves to the next interaction, if 0 is less than 0 it returns -3, this is false
 * it moves to the next interaction which returns the numeric value 0 to the printf in main and it prints it to screen.
 */