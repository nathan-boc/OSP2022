#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LIST_LENGTH 5000000
#define MAX_WORD_LENGTH 300

#define MIN_CHARS 3
#define MAX_CHARS 15

#define testWordList "./wordlists/wlist_match1.txt"

int cmpstr(void const *a, void const *b) { 
    return strcmp(*(const char **)a, *(const char **)b);
}

void Task1Filter(char wordlistFolder[], char cleanFile[]) {

	printf("\nRunning Task1Filter...\n\n");


	printf("Allocating memory for wordlist...\n");

	// Allocate memory for array to hold all words
	char** allWords = malloc(MAX_LIST_LENGTH * sizeof(char*));

	// Allocate memory for each string in the array
	for(int i = 0; i < MAX_LIST_LENGTH; i++) {
		allWords[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
	}

	if(allWords == NULL) {
		printf("ERROR: Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	
	} else {

		printf("Memory allocated for wordlist array.\n\n");


		// Read in words from wordlist
		printf("Reading from input file %s...\n", wordlistFolder);

		printf("\n---------\n\n");

		// Setup input stream to link to the input file
		FILE *fp;
		char inputChar;
		fp = fopen(wordlistFolder, "r");
		
		int currentWordIndex = 0;
		int allWordsIndex = 0;

		// Loop to assign each input character inside the wordlist array
		while(inputChar != EOF) {
			
			inputChar = fgetc(fp);

			if(inputChar != EOF) {
			
				// Checks if there is a numeral or punctuation character and if word is within 3-15 characters
				if(ispunct(inputChar) || isdigit(inputChar) || (currentWordIndex > MAX_CHARS && inputChar != '\n') || (currentWordIndex < MIN_CHARS + 1 && inputChar == '\n')) {
					
					// Loop resets the current string in array
					for(int i = 0; i < currentWordIndex; i++) {
						allWords[allWordsIndex][i] = '\0';
					}

					// Move to next word
					while(inputChar != '\n') {
						inputChar = fgetc(fp);
					}

					currentWordIndex = 0;

				} else {

					// Add current character to the wordlist
					allWords[allWordsIndex][currentWordIndex] = inputChar;

					// Continue to next character if word is not complete
					if(inputChar != '\n') {
						currentWordIndex++;

					} else {

						// TODO: Remove leading and trailing whitespace

						// Allocate memory for a substring
						char* substring = malloc(currentWordIndex);

						bool wordExists = false;

						// Check if word already exists in the wordlist
						for(int i = 0; i < allWordsIndex; i++) {

							strncpy(substring, allWords[i], currentWordIndex + 1);

							if(strcmp(substring, allWords[allWordsIndex]) == 0) {
								wordExists = true;
							}
						}

						free(substring);

						// Move on to next word if word exists, else it will be overwritten
						if(wordExists == false) {
							printf("Added string: %s", allWords[allWordsIndex]);

							allWordsIndex++;
						}

						wordExists = false;	
						currentWordIndex = 0;

						// for loop to identify start and end character and then remove whitespaces (' ' or '\t')


						
					}
				}
			}			
		}

		printf("\n---------\n\n");

		fclose(fp);

		printf("Input read successfully.\n\n");


		printf("Sorting all words...\n");

		qsort(allWords, allWordsIndex, sizeof(char*), cmpstr);

		printf("All words sorted.\n\n");


		// Output formatted words to file
		printf("Writing to output file...\n");

		// Setup output stream to link to the output file
		FILE *fo;
		fo = fopen(cleanFile, "w");

		// Write all words from the array to the output stream
		for(int i = 0; i < allWordsIndex + 1; i++) {
			fputs(allWords[i], fo);
		}

		fclose(fo);

		printf("All words written to file \'%s\'\n\n", cleanFile);
		

		// Free array memory
		printf("Freeing memory...\n");

		// Free memory for the wordlist array
		for(int i = 0; i < MAX_LIST_LENGTH; i++) {
			free(allWords[i]);
		}

		printf("Wordlist array memory freed.\n\n");
		
	}
	

	


	// Shuffle array of words


}

/*
char* removeWhiteSpace(char words[][MAX_WORD_LENGTH]) {

	printf("method called");
	return &words;
}
*/
