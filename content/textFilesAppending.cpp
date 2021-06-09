#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("sampleText.txt", "a");
	fprintf(fp, "Test One\n");
	fputc('a', fp);
	fputs("\nTest Two\n", fp);
	fclose(fp);
}
