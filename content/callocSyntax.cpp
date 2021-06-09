#include <stdio.h>
#include <stdlib.h>

int main() {
	int arrayElementCount;
	int *ptr;
	
	printf("Enter How Many Values: ");
	scanf("%d", &arrayElementCount);
	printf("\n");
	
    ptr = (int *) calloc(arrayElementCount, sizeof(int));
    
    for (int i = 0; i < arrayElementCount; i++) {
    	printf("Digit %d After Memory Allocation: %d\n", i + 1, ptr[i]);
	}
	printf("\n");

    for (int i = 0; i < arrayElementCount; i++) {
    	printf("Enter Digit %d: ", i + 1);
    	scanf("%d", &ptr[i]);
	}

    for (int i = 0; i < arrayElementCount; i++) {
    	printf("\nDigit %d: %d", i + 1, ptr[i]);
	}
	
    free(ptr);

    return 0;
}
