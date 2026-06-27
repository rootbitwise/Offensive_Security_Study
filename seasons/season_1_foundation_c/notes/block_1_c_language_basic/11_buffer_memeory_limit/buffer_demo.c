#include<stdio.h>
#include<stdint.h>

/*
 Purpose of this program: to see what happens when reading values ​​from an array versus
reading data that does not belong to the array. 
*/

/* Declare an array to store 5 values; since there are no negative numbers,
the array is declared as unsigned. */

int main(void){

unsigned int buffer_demo[] = {6,18,7,9,11};

/* Declare a variable to store the total size of the array and use it in the loops
 to avoid hardcoding the array size every time you iterate through the array.*/

size_t size_array = sizeof(buffer_demo) / sizeof(buffer_demo[0]);

// First, traverse the array correctly by reading the exact size.

printf("\n");
printf("Reading the array correctly\n\n"); 

for (size_t truns = 0; truns < size_array; truns++)
{
    printf("The inside value in the array is: %u\n", buffer_demo[truns]);
}

/* 
Now, inside the loop, make `trunks` stop once it exceeds the size of `size_array`,
so that it reads a value outside the array..
*/

printf("\n");
printf("Reading values ​​outside the array on purpose !!!\n\n");

unsigned int more_value = size_array + 3;

for (size_t truns2 = 0; truns2 <= more_value; truns2++)
{
    printf("The inside value in the array is: %u\n", buffer_demo[truns2]);
}

return 0;

}

