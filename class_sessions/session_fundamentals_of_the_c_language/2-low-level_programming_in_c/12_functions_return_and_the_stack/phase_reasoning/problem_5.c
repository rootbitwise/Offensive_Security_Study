#include <stdio.h>
int square(int n)
{
return n * n;
}
int is_even(int n)
{
return (n % 2 == 0);
}
int main(void)
{
int total = 0;
for (int i = 1; i <= 5; i++) {
if (is_even(i)) {
total = total + square(i);
        }
    }
printf("total = %d\n", total);
return 0;
}
/* int is_even is a function that gets passed to the if, it is a function that evaluates if the remainder of the division equals 0
 * if so then it moves to the next line, it says: total equals the value of total added to multiplying the value of i
 * times i, then it prints the total of the final sum to screen
 *
 * Before the first iteration total equals 0
 * It says i equals 1, while i is less than or until i equals 5 increment i by 1
 *
 * i is the argument passed to the variables to perform the operations on each iteration
 *
 * ------------------------------------------------------------------------------------------------------------------------------
 *
 * before entering the loop total equals 0
 *
 * total equals 0
 *
 * on the first iteration i equals 1, the if evaluates the remainder of dividing 1 by 2, since it is not equal to 0 it moves
 * to the next iteration
 *
 * i = 1
 *
 * 1 % 2 == 0 // no, the remainder is not equal to 0
 *
 * ------------------------------------------------------------------------------------------------------------------------------
 *
 * total is still equal to 0
 *
 * increments i by 1, now i equals 2, the condition is evaluated and since this evaluation is correct it passes and says
 * first the value of i is sent as argument to the square function, 2 * 2 the operation is performed and the result
 * 4 is returned, 0 = 0 + 4, now total equals 4
 *
 * i = 2
 *
 * 2 % 2 == 0 // yes, the remainder equals 0
 *
 * 0 equals 0 + (2 * 2) = 4
 *
 * ------------------------------------------------------------------------------------------------------------------------------
 *
 * On this iteration i equals 3, 3 does not pass the condition because the remainder of dividing 3 by 2 is not equal to 0
 * i = 3
 *
 * 3 % 3 == 0 // No the remainder is not equal to 0
 *
 * ------------------------------------------------------------------------------------------------------------------------------
 *
 * Now i equals 4, same as before the value of i(4) is passed as argument to the is_even function and the
 * result is returned, the remainder of 4 divided by 2 is equal to 0, 0 == 0 so the condition passes and now it sends the value
 * 4 as argument to the square function, this function performs the operation 4 * 4 = 16 and returns the result, now it says total = 4 + 16 = 20
 * that value is passed to total
 *
 * i = 4
 * 4 % 4 == 0 // Yes the remainder equals 0
 * 4 = 4 + (4 * 4) = 20
 *
 * ------------------------------------------------------------------------------------------------------------------------------
 *
 * i = 5
 *
 * now i equals 5, 5 is passed as argument to the is_even function and the result is returned, then it evaluates if the remainder
 * equals 0, since it does not then it exits the loop and prints total to screen with the last value that total obtained which is 20
 *
 * and closes the program.
*/