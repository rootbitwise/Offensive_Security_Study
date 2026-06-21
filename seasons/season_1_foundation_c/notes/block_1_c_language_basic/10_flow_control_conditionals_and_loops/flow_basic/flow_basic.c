// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | 1. Un for que imprima los numeros del 1 al 20.                            |
// + * Si el numero es multiplo de 3, imprime fizz en lugar del numero         +
// | * Si el numero es multiplo de 5. imprime buzz                             |
// + * Si el numero es multiplo de ambos (15), imprime fizzbuzz                +
// | * Si no, imprime el numero.                                               |
// +                                                                           +
// |  2. Un while que cuente hacia atras desde 10 hasta 0                      |
// +                                                                           +
// |  3. Un switch que tome un numero del 1 al 7 (constante en el codigo) e    |
// +   imprima el dia de la semana correspondiente.                            +
// |                                                                           |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


#include <stdio.h>

int main(void){


// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | 1. Hacer dos variables que guarden el resultado de dividir i entre 3 y la |
// +   otra entre 5                                                            +
// | 2. Hacer otra variable que sume el resultado de ambas variables.          |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+



printf("=================================\n");
printf("| FLOW BASIC, PROGRAMA FIZZBUZZ |\n");
printf("=================================\n");


	for (int i = 1; i <= 20; i++){
	
	// variables del codigo.
	
	int jump3 = i % 3;
	int jump5 = i % 5;	
	int jumping = jump5 + jump3;
	
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | 1. compara el resultado de sumar el residuo de la division de 3 entre el  |
// +   valor de i y la division de 5 entre i y si el resultado es 0 entonces   +
// |     imprime fizzbuzz, para decir que es multiplo de 15.                   |
// +                                                                           +
// | 2. comparar la division entre el valor de i con 3, si el resultado es 0   |
// +    imprimir fizz                                                          +
// |                                                                           |
// + 3. comprar la division entre el valor de i con 5, si el resultado es 0    +
// |    imprime buzz                                                           |
// +                                                                           + 
// | 4. si el numero no es multiplo de 3 o de 5 entonces imprime el valor de i |        
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+



		if (jumping == 0)
		{
			// si jumping es igual a 0 imprime fizzbuzz
			printf("fizzbuzz\n");
		}
		else if (jump3 == 0)
		{
			// Si jump3 es igual a 0 entonces imprime fizz
			printf("fizz\n");
		}
		else if (jump5 == 0 )
		{	
			// Si jump5 es igual a 0 entonces imprime buzz 
			printf("buzz\n");
		}
		else 
		{
			printf("%d\n", i);
		}
  }
 

printf("================\n");

	int y = 10; 

//imprime una cuenta regresiva desde 10 hasta 0
 
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
				printf("Hoy es Lunes\n");
				printf("-----------------\n");
			break;

			case 2: 
				printf("Hoy es Martes\n");
				printf("-----------------\n");
			break;

			case 3:
		        	printf("Hoy es Miercoles\n");
				printf("-----------------\n");
			break;

			case 4:
				printf("Hoy es Jueves\n");
				printf("-----------------\n");
			break;

			case 5:
				printf("Hoy es Viernes\n");
				printf("-----------------\n");
			
			break;

			case 6:
				printf("Hoy es Sabado\n");
				printf("-----------------\n");
			break;

			case 7: 
				printf("Hoy es Domingo\n");
				printf("-----------------\n");
			break;	
		}
	}


return 0;
}	
