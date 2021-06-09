#include <stdio.h>

class Movie {
	public:
		const char *title;
		int releasedYear;
		
		// This is a Constructor
		Movie (const char *passedTitle, int passedReleasedYear) {
			title = passedTitle;
			releasedYear = passedReleasedYear;
		}
		
		int yearsSinceReleased(int currentYear) {
			return currentYear - releasedYear;
		}
};

int main() {
	Movie movie1("Good Will Hunting", 1997);
	Movie *movie2 = new Movie("Lost in Translation", 2003);
	
	int currentYear = 2020;
	printf("Years Since %s Released: %d\n", movie1.title, movie1.yearsSinceReleased(currentYear));
	printf("Years Since %s Released: %d", movie2->title, movie2->yearsSinceReleased(currentYear));
}
