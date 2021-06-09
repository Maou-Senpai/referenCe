#include <stdio.h>

typedef struct movie {
	const char *title;
	int releasedYear;
} Movie;

int main() {
	Movie movie1;
	Movie *movie2 = new Movie;
	
	movie1.title = "Good Will Hunting";
	movie1.releasedYear = 1997;
	movie2->title = "Lost in Translation";
	movie2->releasedYear = 2003;
	
	printf("%s\n", movie1.title);
	printf("%d\n", movie1.releasedYear);
	printf("%s\n", movie2->title);
	printf("%d", movie2->releasedYear);
}
