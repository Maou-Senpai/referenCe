#include <stdio.h>

int main() {
	int arraySize;
	
	printf("Enter Array Size: ");
	scanf("%d", &arraySize);
	
	try {
		int *sampleArray = new int[arraySize];
		printf("Success");
	}
	catch (...) {
		printf("Fail");
	}
}
