#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MIN_CHARS 3
#define MAX_CHARS 15

#define MAX_LIST_LENGTH 5000000
#define BUFFER_SIZE 300

int cmpstr(void const *a, void const *b) { 
    return strcmp(*(const char **)a, *(const char **)b);
}

void Task1Filter(char dirtyFile[], char cleanFile[]) {

	printf("\nRunning Task1Filter...\n\n");

	// Array of strings to hold all words
	char** allWords = malloc(sizeof(char*));

	// Setup input stream to link to the input file
	FILE *fp;
	fp = fopen(dirtyFile, "r");

	char buffer[BUFFER_SIZE];
	int wordCount = 0;

	bool isValidWord;

	printf("Reading from input file %s...\n", dirtyFile);

	printf("\n---------\n\n");

	// Loop to retrieve words from list
	while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {

		isValidWord = true;

		// Loop to check the retrieved word - excludes the end newline character
		for(int i = 0; i < strlen(buffer) - 1; i++) {

			// Flag words containing numbers and punctuations as invalid
			if(ispunct(buffer[i]) || isdigit(buffer[i])) {
				isValidWord = false;
			}
		}

		// Checks if word is within the 3-15 character limit
		if(strlen(buffer) - 2 > MAX_CHARS || strlen(buffer) - 2 < MIN_CHARS) {
			isValidWord = false;
		}


		// Checks if word already exists in the wordlist
		for(int i = 0; i < wordCount; i++) {

			if(strcmp(buffer, allWords[i]) == 0) {
				isValidWord = false;
			}
		}

		if(isValidWord == true) {
			
			//printf("accepted: %s", buffer);

			wordCount++;

			// Allocate memory for a new word in the list
			allWords = realloc(allWords, wordCount * sizeof(char*));

			// Allocate memory for the characters in the new word
			allWords[wordCount - 1] = malloc(strlen(buffer) * sizeof(char));

			// TODO - CHECKS IF alloc was successful - if alloc == null, error


			strcpy(allWords[wordCount - 1], buffer);
		}

		// Reset contents of the buffer
		memset(buffer,'\0',strlen(buffer));
	}

		printf("\n---------\n\n");

		fclose(fp);

		printf("Input read successfully.\n\n");

		printf("Sorting all words...\n");

		qsort(allWords, wordCount, sizeof(char*), cmpstr);

		printf("All words sorted.\n\n");


		// Output formatted words to file
		printf("Writing to output file...\n");

		// Setup output stream to link to the output file
		FILE *fo;
		fo = fopen(cleanFile, "w");

		// Write all words from the array to the output stream
		for(int i = 0; i < wordCount; i++) {
			fputs(allWords[i], fo);
		}

		fclose(fo);

		printf("All words written to file \'%s\'\n\n", cleanFile);
		

		// Free array memory
		printf("Freeing memory...\n");

		// Free memory for the wordlist array
		for(int i = 0; i < wordCount; i++) {
			free(allWords[i]);
		}

		free(allWords);

		printf("Wordlist array memory freed.\n\n");
		
	}

