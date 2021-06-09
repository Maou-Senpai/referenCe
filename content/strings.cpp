#include <stdio.h>

int main() {
	char word[] = "hello";
	printf("%s\n\n", word);
	
	char inputWord[10];
	printf("Input Word: ");
	scanf("%s", &inputWord);
	printf("Scanned Word: %s", inputWord);
}
