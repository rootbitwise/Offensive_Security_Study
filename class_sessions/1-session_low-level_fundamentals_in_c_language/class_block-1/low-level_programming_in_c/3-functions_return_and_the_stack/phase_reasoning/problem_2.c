#include <stdio.h>
void increment(int n)
{
n = n + 1; // the value of the copy is modified
printf("modified copy : %d\n", n); // the copy is printed
}
int main(void)
{
int value = 10;  // the variable is declared and initialized
increment(value); // the function is called and a copy of the value is passed as argument
printf("inside the stack frame of main: %d\n", value); // the original value is printed
return 0;
}
/* First the function is declared above main so the compiler knows it before main calls it
 * This increment function receives as argument a copy of the original value of the variable value, modifies it
 * and then prints it to screen.
 *
 * Inside main the variable value is declared and initialized
 * The increment function is called, a copy of the original value is passed as argument and then the
 * tasks inside the scope of that function are performed, when it jumps to the next interaction point of main
 *
 * The printf in main shows the original value of the variable value, because at no point inside the scope of main
 * was the value of this variable modified.
 *
 * The value does get modified but outside the stack of main so the value inside main remains the same.
 */