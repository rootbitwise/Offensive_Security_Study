#include <stdio.h>

int main(void)
{
	unsigned char data = 'A';
	unsigned char key = 0x2A;

	unsigned char encrypt = data ^ key; 
	unsigned char recovered = encrypt ^ key;

	/* The reversible property of XOR allows encrypted data to be recovered as long as the 
	 * same key used to encrypt the is used. (A XOR B) XOR B = A
	 *
	 *  data : 0x41
	 *  key :  0x2A ^
	 *  ------------
	 *  result: 0x6B
	 *
	 *  data encrypt 
	 *
	 *  0100 0001 
	 *  0010 1010 ^
	 *  ---------
	 *  0110 1011
	 * 
	 *  decrypt  
	 * 
	 *  0110 1011
	 *  0010 1010 ^
	 *  ---------
  	 *  0100 0001
	 * 
	 *  ------------------
	 *  0x41 ^ 0x2A = 0x6B 
	 *  0x6B ^ 0x2A = 0x41
	 */

	printf("dato = 0x%02X (%c)\n", data, data);
	printf("clave = 0x%02X\n", key);
	printf("cifrado = 0x%02X\n", encrypt);
	printf("recuperado = 0x%02X (%c)\n", recovered, recovered);

return 0;	

}
