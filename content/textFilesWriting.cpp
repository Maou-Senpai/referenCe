#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("sampleText.txt", "w");
	fprintf(fp, "Test One\n");
	fputc('a', fp);
	fputs("\nTest Two", fp);
	fclose(fp);
}
