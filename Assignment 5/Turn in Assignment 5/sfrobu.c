#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void * frobcmp(char const * a, char const * b);
inline void memAllocChecker(void * ptr);
int ioChecker(size_t IO);
int FROBCMP(const void * a, const void * b);
char disfrobbed(const char x);
int die(const char*msg);

#define SPACE ' '
#define initialSize 50

int main(int argc, char * argv[])
{
	if (argc > 2)
	{
		fprintf(stderr, "Incorrect number of arguments. Exiting program.\n");
		exit(1);
	}

	/* Variable Declaration */
	size_t row, col, counter, eof, fSize, numWords;
	FILE * fptr;
	char *word, **wordlist;
	int flag;
	const char * ptr;
	const char * ptr1;
	struct stat buf;
	size_t IO;

	/* Variable Initialization */
	row = col = counter = numWords = 0;
	counter = 0;
	fptr = stdin;
	flag = 0;
	ptr = argv[1];
	ptr1 = '-f';
	IO = read(0, word, 1);

	//if (fptr == NULL)
	//{
	//	printf("Error opening file.");
	//	exit(1);
	//}

	if (strcmp(ptr, ptr1) == 0)
	{ //essentially checking if the option -f was used or not. 
		//From cplusplus.com, strcmp(arg1,arg2) being equal to zero means the contents of both strings are equal
		flag = 1;
	}

	if (strcmp(ptr, ptr1) != 0)
	{
		//i.e. the strings are not equal so additional option -f was not used
		fprintf(stderr, "-f not used. Exiting program.\n");
		exit(1);
	}

	int ret = fstat(0, &buf);
	if (ret < 0)
	{
		fprintf(stderr, "Encountered error with fstat function. Exiting program.\n");
		exit(1);
	}

	printf("ret=%d, file sz=%d\n", ret, buf.st_size);

	char * bufferr = (char*)malloc(buf.st_size * sizeof(char));
	memAllocChecker(bufferr);

	//Now checking for more errors:
	if (feof(stdin))
	{
		buf.st_size = 0;
	}

	if (read(0, bufferr, buf.st_size) < 0)
	{
		fprintf(stderr, "There was an error when reading from file. Exiting program.\n");
		exit(1);
	}
	else {
		bufferr = buf.st_size;
	}

	/* Starting memory allocation */
	wordlist = (char**)malloc(sizeof(char*)); //allocating words at wordlist[0]
	memAllocChecker(wordlist);
	wordlist[0] = malloc(sizeof(char));
	word = (char*)malloc(sizeof(char));
	memAllocChecker(word);

	char ch = ' ';
	ch = fgetc(fptr);


	while ( IO > 0)
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

int ioChecker(size_t IO)
{
	if (IO < 0)
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