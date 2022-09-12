#include <stdio.h>
#include <stdlib.h>

#define WORDLIST_CLEAN "cleanedwords.txt"

extern void Task1Filter(char wordlistFolder[], char cleanFile[]);

int main(int argc, char *argv[]) {

	if(argc == 1 || argc > 3) {
		fprintf(stderr, "Error: Incorrect number of parameters.\n");
		return(EXIT_FAILURE);

	} else if(argc == 2) {
		printf("One parameter passed successfully.\n");

		// If only one arg is passed, provide the default cleanfile name
		Task1Filter(argv[1], WORDLIST_CLEAN);
		
		return(EXIT_SUCCESS);

	} else {
		printf("Two parameters passed successfully.\n");

		// If two args are passed, second arg is used as the cleanfile name
		Task1Filter(argv[1], argv[2]);

		return(EXIT_SUCCESS);
	} 

}