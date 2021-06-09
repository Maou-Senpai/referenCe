#include <stdio.h>
#include "header.h"

int main() {
	int choice, num1, num2, ans = 0;
	
	printMenu();
	scanf("%d", &choice);
	printf("Input First Number: ");
	scanf("%d", &num1);
	printf("Input Second Number: ");
	scanf("%d", &num2);
	
	if (choice == 1) ans = add(num1, num2);
	else if (choice == 2) ans = subtract(num1, num2);
	else if (choice == 3) ans = multiply(num1, num2);
	else if (choice == 4) ans = divide(num1, num2);
	
	printf("\nAnswer: %d", ans);
}
