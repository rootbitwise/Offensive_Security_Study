// #================================================================================================#
// # Escribe un programa que tome un numero entre 0 y 255 (definelo como una constante en el codigo #
// # no hace falta input por teclado todavia) y muestre un analisis copleto de ese byte.            #
// #                                                                                                #
// # Debe mostrar :                                                                                 # 
// #                                                                                                # 
// # * El valor en decimal                                                                          #
// # * El valor en hexadecimal                                                                      # 
// # * El valor intrepretado como signed                                                            #
// # * El valor interpretado como unsigned                                                          #
// # * Si el numero es par o impar                                                                  #
// # * Cuantos bits encendidos (en 1) tiene el byte                                                 #
// #                                                                                                # 
// #================================================================================================# 


#include <stdio.h>

int main() {
	
printf("\n");
printf("#======================================#\n");
printf("#=====|  WELCOME TO BIT ANALYZER |=====#\n");
printf("#======================================#\n");
printf("\n");

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 1. Declarar dos  varibales en formato constante, una que guarde el valor total con signo                        |
//|  y luego guardar la otra haciendo truncamiento para evitar signed extension al guardar el valor en signed char  |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  

unsigned int valor = 200;
signed char valor_signo = valor;

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 2. Usar un bucle for declarar i de tamano 7 para mostrar solo los 8 bits bajos del valor, mintras i siga siendo |
//+  mayor que 0 o hasta que sea igual a 0 ir decementando 1 a i, decalar una variable que haga la operacion de     +
//|   de mover el valor de la variable $valor a nivel de bit luego ir capturando el bit su posicion actual          |
//+     aislandolo con el operador & (AND) y por ultimo mostrar por pantalla cada vuelta del bucle para formar el   +
//|     valor en formato binario.                                                                                   |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("========================================\n");
printf("* EL VALOR INTERPRETADO COMO BINARIO\n");
printf("----------------------------------------\n");
printf("BINARIO : ");

for (int i = 7; i >= 0; i--){
	
	int bit = (valor >> i) &1;	
        printf("%d", bit);
	
	}	

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 3. Mostrar por pantalla el valor de la variable unsigned en formato decimal                                     |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 
printf("\n========================================\n");
printf("----------------------------------------\n");
printf("* EL VALOR INTERPRETADO COMO DECIMAL\n");
printf("DECIMAL : %u\n", valor);

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 4. Tomar la variable con valor unsigned y dividirlo con el operador de modulo y luego comparar el resultado     |
//|  con 0, si el resultado es igual a 0 mostrar como numero par y si es distinto de 0 mostrar como impar.          |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// como la variable es especifica de 32-bits no hay problemas por comversion implicita o por signed extension.

printf("========================================\n");
printf("----------------------------------------\n");
int divisor = valor % 2;

 if (divisor == 0){
	 printf("* EL VALOR: %d ES UN NUMERO PAR\n", valor);
 	          }  else {
			printf("* EL VALOR: %d ES UN VALOR IMPAR\n", valor);
			}	 

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 5. Mostrtar por pantalla el valor unsigned interpretado como numero hexadecimal                                 |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("========================================\n");
printf("* EL VALOR INTERPRETADO COMO NUMERO HEX\n");
printf("----------------------------------------\n");
printf("HEXADECIMAL : 0x%X\n", valor);

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 6. Truncar el valor de la variable unsigned a una variable de menor tamano de tipo signed y luego mostrar por   |
//|  pantalla el valor de esa variable signed                                                                       | 
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("========================================\n");
printf("* EL VALOR INTERPRETADO COMO SIGNED \n");
printf("----------------------------------------\n");
printf("SIGNED : %d\n", valor_signo);

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//| 7. Tomar la misma logica del paso 2, modificar el bucle en lugar de mostrar por pantalla, capturar los bits     | 
//+   que esten encendidos guardarlos en un array y luego contar el size y mostrar por pantalla la cantidad de bits +
//|    encendidos                                                                                                   |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

return 0;

}
