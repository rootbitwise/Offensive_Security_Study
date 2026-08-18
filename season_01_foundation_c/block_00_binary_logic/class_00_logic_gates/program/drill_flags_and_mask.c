#include <stdio.h>

int main(void)
{
	// flgas: bit0 = read, bit1 = write, bit2 = exec


unsigned char flags = 0x05; 

unsigned char m_read = 0x01;
unsigned char m_write = 0x02;
unsigned char m_exec  =  0x04;

printf("flags = 0x%02X\n\n", flags);


/* flags & mask is applying a mask to the flags and (flags & mask) != 0 is checking if the result of
 * that mask is different from 0, (normalize to 1/0).
*/    


/* (1: m_read = 0x01). The result of the mask is 1, and the result of the check is 1; they coincide in the result,
 * but they are not the same operation. 
*/ 

printf("read: flags & mask = %d -> != 0 = %d\n", flags & m_read, (flags & m_read) != 0);



/* (2: m_write = 0x02). The mas result in 0 according to the truth table of AND, and the check 
 * also result in 0 in the same way as the previous chec; they coincide in the result but are 
 * not the same operation. 
*/

printf("write: flags & mask = %d  -> != 0 = %d\n", flags & m_write, (flags & m_write) != 0);



/* (3: m_exec = 0x04). The result of the mask is 4, (note that the mask is not being printed: m_exec
 * 0x04 which is also 4) the result of the mask is 4 and since the decimal format is being used to print
 * to the screen it comes out as 4, the result of the check is 1, because the execute bit is set
*/ 

printf("exec: flags & mask = %d -> != 0 = %d\n", flags & m_exec, (flags & m_exec) != 0 );

return 0; 
}
