#include <stdio.h>


int main(void)
{

unsigned char flags = 0x05;
unsigned char mask = 0x02;

if ((flags | mask) != 0)
{
	printf("write: ON\n");
}
else 
{	
	printf("write: OFF\n");
}

/* The problem here is that the wrong logic gate is being used; an OR gate is being used.
 * OR doesn't check the state of bit; it changes it. OR turns the bit ON or OFF. 
 *
 * This is a salse positive; it is trying to check if the bit is on, but because a different
 * logic gate eas used, the result is ON when in reality the bit is off, but OR is turning on.  
 *
 * flags : 0000 0101
 * mask  : 0000 0010 |
 * -----------------  
 * result: 0000 0111
*/


/* The correct way to check if the bit is on is by using AND 
 *
 * flags : 0000 0101
 * mask  : 0000 0010 &
 * -----------------
 * result: 0000 0000 
*/


printf("\n The result of the check after applying the solution");

if ((flags & mask ) != 0)
{
	printf("write: ON\n");
}
else 
{
	printf("write: OFF\n");
}

return 0;
}
