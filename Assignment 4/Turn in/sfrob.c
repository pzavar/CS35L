#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * frobcmp(char const * a, char const * b);
inline void memAllocChecker(void * ptr);
int ioChecker(void);
int FROBCMP(const void * a, const void * b);
char disfrobbed(const char x);
int die(const char*msg);

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
	fptr = stdin;

	if (fptr == NULL)
	{
		printf("Error opening file.");
		exit(1);
	}

	/* Starting memory allocation */
	wordlist = (char**)malloc(sizeof(char*)); //allocating words at wordlist[0]
	memAllocChecker(wordlist);
	wordlist[0] = malloc(sizeof(char));

	char ch = ' ', prev_ch = ' ';

	while ((ch = fgetc(fptr)) != EOF)
	{
		if (ch == ' ')
		{
			row++;
			wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*));
			memAllocChecker(wordlist);
			wordlist[row] = malloc(sizeof(char));
			memAllocChecker(wordlist);
			col = 0;
		}

		else
		{
			wordlist[row][col] = ch;
									
			col++;
			wordlist[row] = realloc(wordlist[row], (col + 1) * sizeof(char));
			memAllocChecker(wordlist);
		}
	}
	row++;
	qsort(wordlist, row, sizeof(char*), FROBCMP);
	col = 0;
	size_t j = 0;
	for (j; j < row; j++)
	{
		while (wordlist[j][col] >= 'a' && wordlist[j][col] <= 'z')
		{
			putc(wordlist[j][col], stdout);
			col++;
		}
		putc('\n', stdout);
		col = 0;
		free(wordlist[j]);

	}

	free(wordlist);
	fptr = NULL;
	system("pause");
	exit(1);
}

inline void memAllocChecker(void * ptr)
{
	if (ptr == NULL) { die("Allocation failed."); }
}

void * frobcmp(char const * a, char const * b)
{
	for (;; a++, b++)
	{
		if (*a == *b)
			return 0;

		if (*a == SPACE && *b == SPACE)
			return 0;

		if (disfrobbed(*a) < disfrobbed(*b))
			return -1;

		if (*a == SPACE && *b != SPACE) //*a ran out first
			return -1;

		if (disfrobbed(*a) > disfrobbed(*b))
			return 1;

		if (*b == SPACE && *a != SPACE)
			return 1;
	}
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

char disfrobbed(const char x)
{
	return x ^ 42;
}

int FROBCMP(const void * a, const void * b)
{
	const char * i1 = *(const char**)a;
	const char * i2 = *(const char**)b;
	return frobcmp(i1, i2);
}