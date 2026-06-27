#include<stdio.h>
#include<stddef.h>

int main(void){

unsigned int container_array[] = {1,100,200,8,16,9,5,50,173,22};

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | a for loop to access and display all values of the array                                |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

size_t size_array = sizeof(container_array) / sizeof(container_array[0]);

for (size_t a = 0; a < size_array; a++)
{
    printf("%u\n", container_array[a]);
}

printf("\n");

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | initialize a counter variable at 0 outside the loop, and then inside the loop           |
// + keep accumulating the values on each iteration, so when the variable exits it shows     +
// | the total sum of all accumulated values.                                                |
// +                                                                                         +
// | declare two comparison variables to capture the smallest and largest value              |
// + of the array, first initialize the variables at a value already inside the array        +
// | not at 0, because there is no value smaller than 0 to avoid the "menor" variable        |
// + being 0. on each iteration evaluate if the variable is smaller or larger than the       +
// | comparison variable, if so then change the comparison variable value to that one.       |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

unsigned int count = 0;
unsigned int major_comparison = container_array[3];
unsigned int minor_comparison = container_array[3];


for(size_t turns = 0; turns < size_array; turns++)
{
    
    count = count + container_array[turns];

   unsigned int compare_value = container_array[turns];
    
    if (major_comparison < compare_value)
    {
        major_comparison = compare_value;   // if it is larger then replace the variable value with the new value

    }
    
    if (compare_value < minor_comparison) 
    {
        minor_comparison = compare_value; // if smaller then replace the comparacion_menor value with the new value
    }

}

/* To calculate the average, we first cast the `count` variable to a float because decimal precision is required, 
and then divide by `size_array` to obtain the array's average.*/

double average = (double)count / size_array;

printf("the total sum of all values is : %u\n",count);
printf("The smallest value in the array is : %u\n",minor_comparison);
printf("The largest value in the array is : %u\n", major_comparison);
printf("The average of the values within arrays is : %.2f\n", average);
return 0;
}
