#include <stdio.h>
#include <stdint.h>
// #include <stings.h>
// #include <limits.h> 

int main(void)
{


	uint64_t source_buffer[] = {2, 3, '\0'};



	do { 

		for (uint64_t index_column_one = 0; source_buffer[index_column_one] != '\0'; index_column_one++)
		{
			// uint64_t bit_count = (source_buffer[index_column_one] >> index_column_one) &1;
			
			printf("%lu \n", source_buffer[index_column_one]);
		
		}		
		break;
	}
	while (source_buffer[0] != '\0')

return 0;
}
