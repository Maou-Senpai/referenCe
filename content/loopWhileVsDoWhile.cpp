#include <stdio.h>

int main () {
	int i;
	
	printf("Print Loop Counter\n");
	
	i = 1;
	printf("\nFor While:");
	while (i < 1)
	{
		printf("\nThis is Loop %d", i);
		i++;
	}
	printf("\n");
	
	i = 1;
	printf("\nFor Do-While:");
	do
	{
		printf("\nThis is Loop %d", i);
		i++;
	} while (i < 1);
	
	return 0;
}
