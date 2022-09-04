#include <stdio.h>
#include <stdlib.h>

#define WORDLIST_CLEAN "cleanWords.txt"

// extern void Task1Filter(char wordlistFolder[], char cleanFile[]);

int main(int argc, char *argv[]) {

	if(argc == 1 || argc > 3) {
		fprintf(stderr, "Error: Incorrect number of parameters.\n");
		return(EXIT_FAILURE);

	} else if(argc == 2) {
		printf("One parameter passed successfully.");
		// If only one arg is passed, provide the default cleanfile name
		
		return(EXIT_SUCCESS);

	} else {
		printf("Two parameters passed successfully.");
		// If two args are passed, second arg is used as the cleanfile name

		return(EXIT_SUCCESS);
	} 
	
}