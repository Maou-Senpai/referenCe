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

class Documentary : public Movie {
	public:
		// This is a constructor that calls a constructor from the parent class
		Documentary(const char *title, int year, const char *passedLesson) : Movie(title, year) {
			lesson = passedLesson;
		}
		
		const char *getLesson() {
			return lesson;
		}
	
	private:
		const char *lesson;
};

int main() {
	Documentary *doc = new Documentary("Sample Documentary", 2012, "Time is Gold");
	
	printf("%s\n", doc->title);
	printf("%d\n", doc->releasedYear);
	printf("%s\n", doc->getLesson());
	printf("%d Years Since Released", doc->yearsSinceReleased(2020));
}
