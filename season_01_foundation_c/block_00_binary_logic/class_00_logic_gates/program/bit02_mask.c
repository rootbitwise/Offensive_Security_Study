#include <stdio.h>

int main(void)
{

unsigned char flags = 0x06; 

// mask bit 0100 = exec

unsigned char mask = 0x04;

// Checking if the bit is not 0

int has_exec = (flags & mask) != 0;


/*  has_exec checks if the bit at index 2 (0100) is different from 0. 
 *  What (flags & mask) != 0; does is check if the result is different from 0.
 *
 *  flags : 0000 0110
 *  mask  : 0000 0100 &
 *  -----------------
 *  result: 0000 0100 = ON  
*/


	if (has_exec) 
	{
		printf("exec: ON\n");
	}	
 	else
	{	
		printf("exec: OFF\n");
	}

return 0;
}
