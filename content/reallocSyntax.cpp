#include <stdio.h>
#include <stdlib.h>

int main() {
	int arrayElementCount, additionalElementCount;
	int *ptr;
	
	printf("Enter How Many Values: ");
	scanf("%d", &arrayElementCount);
	printf("\n");
	
    ptr = (int *) malloc(arrayElementCount * sizeof(int));

    for (int i = 0; i < arrayElementCount; i++) {
    	printf("Enter Digit %d: ", i + 1);
    	scanf("%d", &ptr[i]);
	}

    for (int i = 0; i < arrayElementCount; i++) {
    	printf("\nDigit %d: %d", i + 1, ptr[i]);
	}
	
	printf("\n\nEnter How Many Additional Values: ");
	scanf("%d", &additionalElementCount);
	printf("\n");
	
	ptr = (int *) realloc(ptr, additionalElementCount * sizeof(int));
	
	for (int i = 0; i < additionalElementCount; i++) {
    	printf("Enter Digit %d: ", i + arrayElementCount + 1);
    	scanf("%d", &ptr[i + arrayElementCount]);
	}

    for (int i = 0; i < additionalElementCount; i++) {
    	printf("\nDigit %d: %d", i + arrayElementCount + 1, ptr[i + arrayElementCount]);
	}
	
    free(ptr);

    return 0;
}
