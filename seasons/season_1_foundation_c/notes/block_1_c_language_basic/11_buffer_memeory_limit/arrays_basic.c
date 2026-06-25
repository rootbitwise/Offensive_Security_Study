#include<stdio.h>

int main(void){

int array_contenedor[] = {1,100,200,8,16,9,5,50,173,22};

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | a for loop to access and display all values of the array                                |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

for (int a = 0; a <= 9; a++)
{
    printf("%d\n", array_contenedor[a]);
}
printf("\n");

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | initialize a counter variable at 0 outside the loop, and then inside the loop           |
// + keep accumulating the values on each iteration, so when the variable exits it shows     +
// | the total sum of all accumulated values.                                                |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int contador = 0;

for (int vueltas = 0; vueltas <= 9; vueltas++)
{
    contador = contador + array_contenedor[vueltas];
}
printf("the total sum of all values is : %d\n",contador);

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | declare two comparison variables to capture the smallest and largest value              |
// + of the array, first initialize the variables at a value already inside the array        +
// | not at 0, because there is no value smaller than 0 to avoid the "menor" variable        |
// + being 0. on each iteration evaluate if the variable is smaller or larger than the       +
// | comparison variable, if so then change the comparison variable value to that one.       |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int comparacion_menor = array_contenedor[3];
int comparacion_mayor = array_contenedor[3];

for (int control = 0; control <= 9; control++)
{
    int comparar_valor = array_contenedor[control];
    
    if (comparacion_mayor < comparar_valor)
    {
    	comparacion_mayor = comparar_valor; // if it is larger then replace the variable value with the new value
    }
    
    if (comparar_valor < comparacion_menor) // if smaller then replace the comparacion_menor value with the new value
    {
        comparacion_menor = comparar_valor;
    }
}

printf("The smallest value in the array is : %d\n",comparacion_menor);
printf("The largest value in the array is : %d\n",comparacion_mayor);

return 0;
}
