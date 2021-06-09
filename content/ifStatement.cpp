#include <stdio.h>

int main() {
	int age;
	
	printf("Input Age: ");
	scanf("%d", &age);
	
	if (age >= 18) {
		printf("Person is an Adult");
	} else if (age >= 13) {
		printf("Person is a Teen");
	} else if (age > 0) {
		printf("Person is a Kid");
	} else {
		printf("Invalid Input");
	}
}
