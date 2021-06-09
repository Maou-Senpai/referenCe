#include <stdio.h>

int main ()
{
	char Array[11] = {'P','R','O','G','R','A','M','M','I','N','G'};
	
	int i;
	
	for (i = 0; i <= 10; i++)
	{
		printf("%c", Array[i]);
	}
	
	printf("\n");
	
	for (i = 0; i <= 10; i++)
	{
		printf("\n%c", Array[i]);
	}

	return 0;
}
