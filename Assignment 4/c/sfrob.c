#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int die(const char * msg);
void * frobcmp(char const * a, char const * b);
inline void memAllocChecker(void * ptr);
int ioChecker(void);
int FROBCMP(const void * a, const void * b);

#define SPACE ' '
#define initialSize 50

int main(void)
{
	/* Variable Declaration */
	size_t row, col, counter, eof, fSize, numWords;
	FILE * fptr;
	char *word, **wordlist;

	/* Variable Initialization */
	row = col = counter = numWords = 0;
	counter = 0;
	eof = feof(stdin);
	fSize = initialSize;
	//fptr = stdin;
	fptr = fopen("testas4.txt", "r");

	if (fptr == NULL)
	{
		printf("Error opening file.");
		exit(1);
	}

	/* Starting memory allocation */
	word = (char*)malloc(sizeof(char));
	memAllocChecker(word);

	wordlist = (char**)malloc(row * sizeof(char*)); //allocating words at wordlist[0]
	memAllocChecker(wordlist);
	wordlist[0] = malloc(sizeof(char));

	char ch = ' ', prev_ch = ' ';

	while (!eof)
	{
		prev_ch = ch;
		ch = getchar();
		ioChecker(stdin);
		eof = feof(stdin);

		wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*)); // Allocate wordlist[row]
		memAllocChecker(wordlist);
		wordlist[row] = malloc(sizeof(char)); // Allocate wordlist[row][0]
		memAllocChecker(wordlist[row]);

		//if (!eof && prev_ch !=0)
		//{
		//	//word[buffSize++] = ch;
		//	col++;
		//}


		if (prev_ch == ' ' && ch == ' ')
		{
			row++;
			wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*));
			memAllocChecker(wordlist);
			wordlist[row] = malloc(sizeof(char));
			memAllocChecker(wordlist);
			col = 0;
			counter++;
		}

		/*if (word == NULL)
		{
		word = (char**)malloc(word,(rowsizeof(char));
		memAllocChecker(word);
		}*/

		else
		{
			wordlist[row][col] = *(word + counter); //  <-------------------------------------------------
			counter++;
			col++;
			wordlist[row] = realloc(wordlist[row], (col + 1) * sizeof(char)); // <------------------------
			memAllocChecker(wordlist);
			//wordlist[row][col] = ' ';

			/*word = (char*)realloc(word, (col + 1) * sizeof(char));
			memAllocChecker(word);*/

		}
	}

	qsort(wordlist, row, sizeof(char*), FROBCMP);

	for (int j = 0; j < row; j++)
	{
		for (int i = 0; i < col && col != ' '; i++)
		{
			putc(wordlist[i][j], stdout);
		}
		putc('\n', stdout);

		free(wordlist[j]);

	}
	free(wordlist);
	fptr = NULL;
	free(word);

	exit(1);
}



inline void memAllocChecker(void * ptr)
{
	if (ptr == NULL) { die("Allocation failed."); }
}

void * frobcmp(char const * a, char const * b)
{
	while (*a == *b)
	{
		if (*a == ' ')
		{
			return 0;
		}
		a++; b++;
	}
	if (*a ^ 42 < *b ^ 42)
		return -1;
	if (*a ^ 42 > *b ^ 42)
		return 1;
}

int die(const char * msg)
{
	printf("Fatal Error: %s\n", msg);
	exit(1);
}

int ioChecker(void)
{
	if (ferror(stdin))
	{
		die("I/O error. Exiting program.");
	}
	else {
		return 1;
	}
}

int FROBCMP(const void * a, const void * b)
{
	const char * i1 = *(const char**)a;
	const char * i2 = *(const char**)b;
	return frobcmp(i1, i2);
}