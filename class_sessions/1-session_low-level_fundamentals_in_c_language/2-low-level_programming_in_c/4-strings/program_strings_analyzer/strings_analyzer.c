#include <stdio.h>
#include <string.h>

int main(void)
{
    /* 
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        | Proposito del programa :                                                        |
        +                                                                                 +
        | El objetivo de este programa es leer una cadena de texto, medir su longitud     |
        + con dos metodos distintos, contar cuantas letras mayusculas y minusculas tiene  +
        | el texto y saber cuantos espacios o cuantos caracteres no son texto.            |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    */
    
    // Declarar un array que contenga el texto objetivo
	/*
		Declarar variables para contar los caracteres totales, la longitud del texto con strlen, los espacios en blanco y las letras minusculas 
		y mayusculas que contenga el texto objetivo 
	
	*/
   
       	char texto_objetivo[] = "Este Es Un Texto De Prueba Para Analizar Cadenas De Texto";
	    unsigned int caracteres_totales = 0;
		unsigned int espacios_en_blanco = 0; 
		unsigned int recorrer_texto = 0;
		int caracteres_minusculas = 0;
		int caracteres_mayusculas = 0;
		size_t longitud_texto = strlen(texto_objetivo);


	// Mostrar en pantalla el la longitud del texto objetivo.

     printf("STRINGS ANALYZER\n\n");
	 printf("La longitud del texto objetivo es: %zu\n", longitud_texto);

    /* 
        Recorrer el array caracter por caracter y deterner la iteracion cuando llegue al null terminador '\0'
        para generar el texto que se mostrara en pantalla y evitar un oob read.
    
    */
	
    for (recorrer_texto = 0; texto_objetivo[recorrer_texto] != '\0'; recorrer_texto++)
    {
        printf("%c", texto_objetivo[recorrer_texto]);

		/*
			contar cuantos caracteres tiene el texto objetivo, si el caracter es un espacio, 
			continuar con la siguiente iteracion sin contar el caracter
		
		*/

		if (texto_objetivo[recorrer_texto] == 32)
		{
			espacios_en_blanco++;
			continue;
		}
		caracteres_totales++;
    }
	
	printf("\nEl texto tiene %u caracteres !sin incluir espacios o caracteres especiales!", caracteres_totales);
	printf("\nEl texto tiene %u espacios en blanco!", espacios_en_blanco);


	/*
		Usar la misma logica para recorrer el texto objetivo y mostrar solo las letras minusculas que contenga el texto
	*/
	printf("\n\n");
	printf("Las letras minusculas que contiene el texto son: \n");

    for (recorrer_texto = 0; texto_objetivo[recorrer_texto] != '\0'; recorrer_texto++)
 	{
	
        if (texto_objetivo[recorrer_texto] >= 'a' && texto_objetivo[recorrer_texto] <= 'z')
		{
			printf("%c",texto_objetivo[recorrer_texto]);
			caracteres_minusculas++;

		}
	}	
 	
	printf("\nEl texto tiene %d letras minusculas!\n", caracteres_minusculas);

	/*
		Usar la misma logica para recorrer el texto objetivo y mostrar solo las letras mayusculas que contenga el texto
	*/
	printf("\n\n");
	printf("Las letras mayusculas que contiene el texto son: \n");
	
	for (recorrer_texto = 0; texto_objetivo[recorrer_texto] != '\0'; recorrer_texto++)
 	{
	
		if (texto_objetivo[recorrer_texto] >= 'A' && texto_objetivo[recorrer_texto] <= 'Z')
		{
			printf("%c",texto_objetivo[recorrer_texto]);
			caracteres_mayusculas++;

		}
	}
	printf("\nEl texto tiene %d letras mayusculas!\n", caracteres_mayusculas);
 
return 0;

}
