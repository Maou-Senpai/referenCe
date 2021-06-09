#include <stdio.h>

int add(int x, int y) {
	int tempAns = x + y;
	return tempAns;
}

int subtract(int x, int y) {
	int tempAns = x - y;
	return tempAns;
}

int multiply(int x, int y) {
	int tempAns = x * y;
	return tempAns;
}

int divide(int x, int y) {
	int tempAns = x / y;
	return tempAns;
}

void printMenu() {
	printf("Pick An Operation:\n");
	printf("1: Addition\n");
	printf("2: Subtraction\n");
	printf("3: Multiplication\n");
	printf("4: Division\n\n");
	printf("Input Choice: ");
}

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
