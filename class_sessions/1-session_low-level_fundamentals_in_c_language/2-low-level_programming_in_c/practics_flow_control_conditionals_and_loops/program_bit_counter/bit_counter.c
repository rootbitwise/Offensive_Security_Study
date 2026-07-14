// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | Hcer un programa que cuente cuantis bits encendidos hay   |
// + 							       +
// | Requisitos : 					       |
// +							       +
// |  1. Tomar un uint8_t con valor constante		       |
// +  2. En cada vuelta extraer el valor del bit               +
// |  3. Contar cunato bits encendidos tiene el bit. 	       |
// +  4. imprimir el total				       +
// |							       |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


#include<stdio.h>
#include<stdint.h>

int main(void)
{


// declarar las variables del programa

uint8_t bits_objetivo = 100;
uint8_t contador = 0;

// Hacer un for para capturar el valor de la variable.

	for (int i = 7; i >= 0; i--)
	{
		uint8_t capturador = (bits_objetivo >> i)&1;

		while (contador < capturador)
		{
			contador++;
			printf("%d\n",contador);
		}
	}

return 0;

}
