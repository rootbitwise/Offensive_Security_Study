#include <stdio.h>


int main(void)
{


	unsigned char data = 0x4b; // data
	
	unsigned char mask_0xff = 0xff; // validation mask 
	
	unsigned char applying_mask_0xff = data & mask_0xff; // applying the mask to the data 

	// Veryfing if the data is valid for discarding or processing
	
	if (mask_0xff == applying_mask_0xff)
	{
		printf("* [ERROR] this is sentinel 0xff");
	}
	else if (data == '\0')
	{
		printf("* [ERROR] data is zero");
	}
	else 
	{
		
		unsigned char mask_exec = 0x08;  

		unsigned char verifying_permission = (mask_exec & data) != 0;

		if (verifying_permission)
		{
			printf("EXEC ON %d\n", verifying_permission);
		}
		else 
		{
			printf("EXEC OFF %d\n", verifying_permission);
		}


		// Mask to invert the 0 bit of the data: 0x4b

		unsigned char invert_bit = 0x01;
		unsigned char invert_0_bit = data ^ invert_bit;

		printf("The data with the 0 bit inverted : 0x%x\n", invert_0_bit);
		
		
	}


return 0;
}
