#include <stdio.h>
int doubler(int x)
{
return x * 2;
}
int main(void){
int a = 5; // original value
int b = doubler(a); // a copy of the original value is passed to the doubler function
printf("original value : %d\n copy manipulation :  %d\n", a, b); // both values are printed to screen
return 0;
}
/* First a function is declared above main so the compiler knows it
 * a copy of the original value of a found in main is passed to that function
 * this function can only manipulate the copy not the original value.
 *
 * The original value is in another stack frame, that is why the function gets a copy of the original
 * value.
 *
 * Inside the scope of main the original variable is declared, then with int b = doubler(a);
 * the value of a is copied and passed as argument to the doubler function, the function does not access the
 * location of the original variable it only receives a copy of its value
 *
 * Finally both are printed to screen.
*/