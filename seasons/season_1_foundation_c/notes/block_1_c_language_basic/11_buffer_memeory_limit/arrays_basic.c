#include<stdio.h>

int main(void){

int array_contenedor[] = {1,100,200,8,16,9,5,50,173,22};

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | un bucle for para acceder y mostrar todos los valores del array                        |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

for (int a = 0; a <= 9; a++)
{
    printf("%d\n", array_contenedor[a]);
}

printf("\n");

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | inicializar una variable contador en 0 fuera del bucle, y luego dentro del bucle        |
// + is acumulando los valores en cada vuelta, para cuando la variable salga mostrar ls      +
// | suma total de todos los valores acumulados.                                             |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int contador = 0;

for (int vueltas = 0; vueltas <= 9; vueltas++)
{
    contador = contador + array_contenedor[vueltas];
}

printf("la suma total de todos los valores es : %d\n",contador);

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | declarar dos varibales de comparacion para capturar el valor menor y el valor mayor     |
// + del array, primero incializar las variables en un valor que ya este dentro del array    +
// | no en 0, porque no hay valor menor a 0 para evitar que la variable "menor" sea 0.       |
// + en cada vuelta evaluar si la variable es menor o mayor que la variable de comparacion   +
// | si es asi enronces cambiar el valor de la variable comparacion por ese.                 |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int comparacion_menor = array_contenedor[3];
int comparacion_mayor = array_contenedor[3];

for (int control = 0; control <= 9; control++)
{
    int comparar_valor = array_contenedor[control];

    if (comparacion_mayor < comparar_valor)
    {
        comparacion_mayor = comparar_valor; // si es mayor entonces sustiruir el valor de la variable por el nuevo valor
    }
    
    if (comparar_valor < comparacion_menor) // si menor entonces sustituir el valor de la comparacion_menor por el nuevo valor 
    {
        comparacion_menor = comparar_valor;
    }
}

printf("El valor menor del array es : %d\n",comparacion_menor);
printf("El valor mayor del array es : %d\n",comparacion_mayor);

return 0;
}