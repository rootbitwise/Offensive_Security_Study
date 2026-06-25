#include<stdio.h>
#include<stdint.h>

int main(void)
{

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Declarar dos variables, una sin signo de tamano especifico de 32-bits   |
// + otra con signo de tamano especifico de 32-bits.	                     +
// | ambas con el mismo valor decirmal.                                      |                                                        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	 
int32_t var_signed = -32;
uint32_t var_unsigned = var_signed; // 4 mill millones por asignacion implicita


// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Dos bucles for que hacen exactamente lo mismo, primero hacen una cuenta |
// + regresiva de 31 hasta 0, siempre que la variable sea mayor o igual a 0  +
// | disminuye 1 valor a la variable.                                        |
// +                                                                         +
// | cuerpo :                                                                |
// + ------------------------------------------------------------------------+
// | una variable que se mueve n posiciones a la izquierda y aisle solo el   |
// + bit de la posicion en la que se encuenta y luego muestre por pantalla   +
// | ese bit en especifico, para mostrar el valor en formao binario          |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("-----------------------------------\n");
printf("| MOSTRAR CADA BIT DE LA VARIABLE |\n");
printf("-----------------------------------\n");
	
for (int i = 31; i >= 0; i--)
{
 	int32_t bit = (var_signed >> i)&1;
	printf("%d", bit);
}	


printf("\n");
printf("-----------------------------------\n");
printf("|    MOSTRAR DECIMAL DE SIGNED    |\n");
printf("-----------------------------------\n");		
printf("%d\n", var_signed);
	
printf("-----------------------------------\n");
printf("| MOSTRAR LOS BIT DE VAR_UNSIGNED |\n");
printf("-----------------------------------\n");

for (int i = 31; i >= 0; i--)
{
	uint32_t bit_unsigned = (var_unsigned >> i)&1;
	printf("%u", bit_unsigned);
}	

printf("\n");
printf("-----------------------------------\n");
printf("| MOSTRAR EL DECIMAL DEL UNSIGNED |\n");
printf("-----------------------------------\n");
printf("%u",var_unsigned);
printf("\n");

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Usar una mascara con NOT para apagar los 32-bits de la var_unsigned     |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

printf("-----------------------------------\n");
printf("| INVERTIR LOS BIT DE VAR_UNIGNED |\n");
printf("-----------------------------------\n");

for (int i = 31; i >= 0; i--)
{

	uint32_t bits = (var_unsigned >> i) &1;

	uint32_t not_bits = ~bits &1;	
	printf("%u",not_bits);
}
	
	return 0;
}
