#include <stdio.h>

int main(void){


printf("\n int a = -1, is a 32-bits. when convertd long long variable is 64-bits, its recives value 1111 1111 1111... and continue until the 64-bits are set. \n It recives that value through a signed extention; its remains -1 but in 64-bits\n");


	int x = -1;
	unsigned long long y = x;
	
	printf("=======================");
	printf("\n %lld", y);

	return 0;


}
