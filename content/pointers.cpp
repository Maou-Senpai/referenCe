#include <stdio.h>

void withoutPointer(int tempNumber) {
	tempNumber += 5;
	printf("Value Inside withoutPointer Function: %d\n", tempNumber);
}

void withPointer(int *tempNumber) {
	*tempNumber += 5;
	printf("Value Inside withPointer Function: %d\n", *tempNumber);
}

int main() {
	int number = 5;
	
	withoutPointer(number);
	printf("Value After withoutPointer Function: %d\n\n", number);
	withPointer(&number);
	printf("Value After withPointer Function: %d", number);
}
