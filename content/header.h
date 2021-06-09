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
