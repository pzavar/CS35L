////#include <stdio.h>
////#include <stdlib.h>
////#include <string.h>
////
////void * frobcmp(char const *a, char const *b);
////char disfrobbed(const char x);
////int FROBCMP(const void * x1, const void * x2);
////inline void memAllocChecker(void * ptr);
////int ioChecker(void);
////int die(const char * msg);
////
////#define SPACE ' '
////
////int main()
////{
////	FILE * fptr;
////	fptr = fopen("test.txt", "r");
////	if (fptr == NULL)
////	{
////		die("Could not open file. Exiting.");
////	}
////
////	char * curWord; //stores variably sized string
////	char ** allWord; //stores pointers to curWord
////
////	curWord = (char*)malloc(sizeof(char)); //allocate space for 1 character
////	memAllocChecker(curWord);
////	allWord = NULL; //no words yet added so NULL
////
////	size_t numLetters = 0; // # of letters in curWord
////	size_t numWords = 0; // # of words in allWord (i.e. rows)
////
////	//curWord[numLetters] = getchar();
////	//char ch = getchar(); -----------------------------------------------------------------------
////	//curWord[numLetters] = ch; ----------------------------------------------------------------- dont delete dont forget 
////	char ch = ' ';
////
////	/*if (!ioChecker())
////	{
////		free(curWord);
////		exit(1);
////	}*/
////
////	/*char chnext = getchar();*/
////
////
////	//while (curWord[numLetters] != EOF) <----------------------------------------------------------- important line DONT DELETE
////	while ((ch = fgetc(fptr)) != EOF)
////	{
////		if (!ioChecker())
////		{
////			free(curWord);
////			exit(1);
////		}
////
////		curWord[numLetters] = ch;
////
////		char chnext = getchar();
////
////		while (chnext == ' ')
////		{
////			chnext = getchar();
////			ioChecker();
////		}
////
////		if (curWord[numLetters] == ' ' && chnext != EOF)
////		{
////			allWord = (char**)realloc(allWord, (numWords+1) * sizeof(char*) + sizeof(char*));
////			if (allWord != NULL)
////			{
////				allWord[numWords] = ch; 
////				numWords++; //going one row down
////				numLetters = 0;
////				curWord = (char*)malloc(sizeof(char)); //making space for character
////			}
////			else {
////				free(curWord);
////				for (size_t i = 0; i < numWords; i++)
////					free(allWord[i]); //freeing individual elements inside the array
////				free(allWord); //freeing the actual array
////				die("Allocation failure. Exiting");
////			}
////		}
////
////		else if (chnext == EOF)
////		{
////			break;
////		}
////
////		/*else if (x == ' ')
////		{
////			allWord = (char**)realloc(allWord, (numWords + 1) * sizeof(char*) + sizeof(char*));
////			numLetters = 0;
////			numWords++;
////		}*/
////
////		//Ats = realloc(Ats, (*kiekis + 1) * sizeof(char*));
////
////		curWord = realloc(curWord, (numLetters + 1) * sizeof(char*));
////		if (curWord == NULL)
////		{
////			for (size_t i = 0; i < numWords; i++)
////				{
////					free(allWord[i]);
////				}
////				free(curWord);
////				free(allWord);
////				die("Allocation failure. Exiting.");
////		}
////		else {
////			chnext = getchar();
////			ioChecker();
////			numLetters++;
////		}
////		//char * w = realloc(curWord,numLetters * sizeof(char*) + sizeof(char*)); //I think the mistake is here
////		//if (w == NULL)
////		//{
////		//	for (size_t i = 0; i < numWords; i++)
////		//	{
////		//		free(allWord[i]);
////		//	}
////		//	free(curWord);
////		//	free(allWord);
////		//	die("Allocation failure. Exiting.");
////		//}
////		//else {
////		//	curWord[numLetters] = w;
////		//	chnext = getchar();
////		//	ioChecker();
////		//	numLetters++;
////		//}
////
////
////		/*curWord = realloc(curWord, numLetters * sizeof(char*) + sizeof(char*)); --------------------------------------------------------
////		if (curWord == NULL)
////		{
////			for (size_t i = 0; i < numWords; i++)
////			{
////				free(allWord[i]);
////			}
////			free(curWord);
////			free(allWord);
////			die("Allocation failure. Exiting.");
////		}
////		else if (curWord != NULL)
////		{
////			curWord[numLetters] = chnext;
////		}*/
////		
////
////		//else //when you encounter a letter instead of a space
////		//{
////		//	allWord[numWords][numLetters] = curWord[numLetters];  // <-------------------------------------- this line throws exception
////		//	numLetters++;
////		//	char * p = realloc(curWord, numLetters * sizeof(char*) + sizeof(char*));
////		//	if (p != NULL)
////		//	{
////		//		curWord = p;
////		//		curWord[numLetters] = chnext;
////		//	}
////		//	else if (p == NULL)
////		//	{
////		//		for (size_t i = 0; i < numWords; i++)
////		//		{
////		//			free(allWord[i]);
////		//		}
////		//		free(curWord);
////		//		free(allWord);
////		//		die("Allocation failure. Exiting.");
////		//	}
////		//}
////
////	} //end of while loop
////
////	/* Sorting the words using built-in qsort function */
////	qsort(allWord, numWords, sizeof(char*), FROBCMP);
////
////	/* printing... */
////	for (size_t i = 0; i < numWords; i++)
////	{
////		for (size_t j = 0; allWord[i][j] != ' '; j++)
////			putc(allWord[i][j], stdout);
////		putc('\n', stdout);
////		free(allWord[i]);
////	}
////	/*for (size_t i = 0; i < numWords; i++)
////	{
////		for (size_t j = 0; allWord[i][j] != ' '; j++)
////			printf(allWord[i][j]);
////		printf("%c", '\n');
////		free(allWord[i]);
////	}*/
////
////	system("pause");
////	exit(1);
////}
////
/////* Function to use within qsort without having to cast */
////int FROBCMP(const void * x1, const void * x2)
////{
////	const char*a = *(const char**)x1;
////	const char*b = *(const char**)x2;
////	return frobcmp(a, b);
////}
////
/////* Checking if dynamic memory is allocated properly */
////inline void memAllocChecker(void * ptr)
////{
////	if (ptr == NULL) die("Allocation failed. Exiting.\n");
////}
////
////int ioChecker(void)
////{
////	if (ferror(stdin))
////	{
////		die("I/O error. Exiting program.");
////	}
////	else {
////		return 1;
////	}
////}
////
////int die(const char * msg)
////{
////	printf("Fatal Error: %s\n", msg);
////	exit(1);
////}
////
/////* To not have to every time type ^42 */
////char disfrobbed(const char x)
////{
////	return x ^ 42;
////}
////
////void * frobcmp(char const *a, char const * b)
////{
//	for (;; a++, b++)
//	{
//		/*while (*a == '\0')
//			a++;
//
//		while (*b == '\0')
//			b++;*/
//
//		if (*a == *b)
//			return 0;
//
//		if (*a == SPACE && *b == SPACE)
//			return 0;
//
//		if ((*a^42) < (*b^42))
//			return -1;
//
//		if (*a == SPACE && *b != SPACE) //*a ran out first
//			return -1;
//
//		if ((*a^42) > (*b^42))
//			return 1;
//
//		if (*b == SPACE && *a != SPACE)
//			return 1;
//	}
////}
/////*_____________________________________________________________________________________________________________________________________________________________
////Write a C function frobcmp that takes two arguments a and b as input and returns an int result that
////is negative, zero, or positive depending on whether a is less than, equal to, or greater than b. Each
////argument is of type char const *, and each points to an array of non-space bytes that is followed by
////space byte. Use standard byte-by-byte lexicographic comparison on the non-space bytes, in the style of the
////memcmp function, except that you should assume that both arrays are frobnicated, (i.e., trivally obfuscated
////via memfrob) and should return the equivalent of running memcmp on the corresponding unfrobnicated arrays.
////If one unfrobnicated array is a prefix of the other, then consider the shorter to be less than the longer.
////The space bytes are not considered to be part of either array, so they do not participate in the comparison.
////*/
////
//////#include <stdio.h>
//////#include <stdlib.h>
//////#include <string.h>
//////
//////int die(const char * msg);
//////void * frobcmp(char const * a, char const * b);
//////inline void memAllocChecker(void * ptr);
//////int ioChecker(void);
//////int FROBCMP(const void * a, const void * b);
//////
//////#define SPACE ' '
//////#define initialSize 50
//////
//////int main(void)
//////{
//////	/* Variable Declaration */
//////	size_t row, col, counter, eof, fSize, numWords;
//////	FILE * fptr;
//////	char *word, **wordlist;
//////
//////	/* Variable Initialization */
//////	row = col = counter = numWords = 0;
//////	counter = 0;
//////	// eof = feof(stdin);
//////	//fSize = initialSize;
//////	//	fptr = stdin;
//////	fptr = fopen("test.txt", "r");
//////
//////	if (fptr == NULL)
//////	{
//////		printf("Error opening file.");
//////		exit(1);
//////	}
//////
//////	/* Starting memory allocation */
//////	/*word = (char*)malloc(sizeof(char));
//////	memAllocChecker(word);*/
//////
//////	wordlist = (char**)malloc(sizeof(char*)); //allocating words at wordlist[0]
//////	memAllocChecker(wordlist);
//////	wordlist[0] = malloc(sizeof(char));
//////
//////	char ch = ' ', prev_ch = ' ';
//////
//////	while ((ch = fgetc(fptr)) != EOF)
//////	{
//////		//prev_ch = ch;
//////		//ch = getchar();
//////		//ioChecker(stdin);
//////		//	eof = feof(stdin);
//////		//	wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*)); // Allocate wordlist[row]
//////		//		memAllocChecker(wordlist);
//////		//	wordlist[row] = malloc(sizeof(char)); // Allocate wordlist[row][0]
//////		//	memAllocChecker(wordlist[row]);
//////		//if (!eof && prev_ch !=0)
//////		//{
//////		//	//word[buffSize++] = ch;
//////		//	col++;
//////		//}
//////
//////
//////		if (ch == ' ')
//////		{
//////			row++;
//////			wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*));
//////			memAllocChecker(wordlist);
//////			wordlist[row] = malloc(sizeof(char));
//////			memAllocChecker(wordlist);
//////			col = 0;
//////			//counter++;
//////		}
//////
//////		/*if (word == NULL)
//////		{
//////		word = (char**)malloc(word,(rowsizeof(char));
//////		memAllocChecker(word);
//////		}*/
//////
//////		else
//////		{
//////			wordlist[row][col] = ch; //  <-------------------------------------------------
//////									 //	counter++;
//////			col++;
//////			wordlist[row] = realloc(wordlist[row], (col + 1) * sizeof(char)); // <------------------------
//////			memAllocChecker(wordlist);
//////			//wordlist[row][col] = ' ';
//////
//////			/*word = (char*)realloc(word, (col + 1) * sizeof(char));
//////			memAllocChecker(word);*/
//////
//////		}
//////	}
//////	//	printf("%c", wordlist[0][0]);
//////	qsort(wordlist, row, sizeof(char*), FROBCMP);
//////
//////	for (int j = 0; j < row; j++)
//////	{
//////		for (int i = 0; i < col && col != ' '; i++)
//////		{
//////			putc(wordlist[i][j], stdout);
//////		}
//////		putc('\n', stdout);
//////
//////		free(wordlist[j]);
//////
//////	}
//////	free(wordlist);
//////	fptr = NULL;
//////	//	free(word);
//////	system("pause");
//////	exit(1);
//////}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int die(const char * msg);
//void * frobcmp(char const * a, char const * b);
//inline void memAllocChecker(void * ptr);
//int ioChecker(void);
//int FROBCMP(const void * a, const void * b);
//
//#define SPACE ' '
//#define initialSize 50
//
//int main(void)
//{
//	/* Variable Declaration */
//	size_t row, col, counter, eof, fSize, numWords;
//	FILE * fptr;
//	char *word, **wordlist;
//
//	/* Variable Initialization */
//	row = col = counter = numWords = 0;
//	counter = 0;
//	// eof = feof(stdin);
//	//fSize = initialSize;
//	//	fptr = stdin;
//	fptr = fopen("test.txt", "r");
//
//	if (fptr == NULL)
//	{
//		printf("Error opening file.");
//		exit(1);
//	}
//
//	/* Starting memory allocation */
//	/*word = (char*)malloc(sizeof(char));
//	memAllocChecker(word);*/
//
//	wordlist = (char**)malloc(sizeof(char*)); //allocating words at wordlist[0]
//	memAllocChecker(wordlist);
//	wordlist[0] = malloc(sizeof(char));
//
//	char ch = ' ', prev_ch = ' ';
//
//	while ((ch = fgetc(fptr)) != EOF)
//	{
//		//prev_ch = ch;
//		//ch = getchar();
//		//ioChecker(stdin);
//		//	eof = feof(stdin);
//		//	wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*)); // Allocate wordlist[row]
//		//		memAllocChecker(wordlist);
//		//	wordlist[row] = malloc(sizeof(char)); // Allocate wordlist[row][0]
//		//	memAllocChecker(wordlist[row]);
//		//if (!eof && prev_ch !=0)
//		//{
//		//	//word[buffSize++] = ch;
//		//	col++;
//		//}
//
//
//		if (ch == ' ')
//		{
//			row++;
//			wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*));
//			memAllocChecker(wordlist);
//			wordlist[row] = malloc(sizeof(char));
//			memAllocChecker(wordlist);
//			col = 0;
//			//counter++;
//		}
//
//		/*if (word == NULL)
//		{
//		word = (char**)malloc(word,(rowsizeof(char));
//		memAllocChecker(word);
//		}*/
//
//		else
//		{
//			wordlist[row][col] = ch; //  <-------------------------------------------------
//									 //	counter++;
//			col++;
//			wordlist[row] = realloc(wordlist[row], (col + 1) * sizeof(char)); // <------------------------
//			memAllocChecker(wordlist);
//			//wordlist[row][col] = ' ';
//
//			/*word = (char*)realloc(word, (col + 1) * sizeof(char));
//			memAllocChecker(word);*/
//
//		}
//	}
//	row++;
//	qsort(wordlist, row, sizeof(char*), FROBCMP);
//	col = 0;
//	for (int j = 0; j < row; j++)
//	{
//		while (wordlist[j][col] >= 'a' && wordlist[j][col] <= 'z')
//		{
//			putc(wordlist[j][col], stdout);
//			col++;
//		}
//		putc('\n', stdout);
//		col = 0;
//		free(wordlist[j]);
//
//	}
//
//	/*for (int j = 0; j < row; j++)
//	{
//	for (int i = 0; i < col && col != ' '; i++)
//	{
//	putc(wordlist[i][j], stdout);
//	}
//	putc('\n', stdout);
//
//	free(wordlist[j]);
//
//	}*/
//	free(wordlist);
//	fptr = NULL;
//	//	free(word);
//	system("pause");
//	exit(1);
//}
//
//
//
//inline void memAllocChecker(void * ptr)
//{
//	if (ptr == NULL) { die("Allocation failed."); }
//}
//
//void * frobcmp(char const * a, char const * b)
//{
//	while (*a == *b)
//	{
//		if (*a == ' ')
//		{
//			return 0;
//		}
//		a++; b++;
//	}
//	if (*a ^ 42 < *b ^ 42)
//		return -1;
//	if (*a ^ 42 > *b ^ 42)
//		return 1;
//}
//
//int die(const char * msg)
//{
//	printf("Fatal Error: %s\n", msg);
//	exit(1);
//}
//
//int ioChecker(void)
//{
//	if (ferror(stdin))
//	{
//		die("I/O error. Exiting program.");
//	}
//	else {
//		return 1;
//	}
//}
//
//int FROBCMP(const void * a, const void * b)
//{
//	const char * i1 = *(const char**)a;
//	const char * i2 = *(const char**)b;
//	return frobcmp(i1, i2);
//}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * frobcmp(char const * a, char const * b);
inline void memAllocChecker(void * ptr);
int ioChecker(void);
int FROBCMP(const void * a, const void * b);
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
	// eof = feof(stdin);
	//fSize = initialSize;
	//fptr = stdin;
	fptr = stdin;

	if (fptr == NULL)
	{
		printf("Error opening file.");
		exit(1);
	}

	/* Starting memory allocation */
	/*word = (char*)malloc(sizeof(char));
	memAllocChecker(word);*/

	wordlist = (char**)malloc(sizeof(char*)); //allocating words at wordlist[0]
	memAllocChecker(wordlist);
	wordlist[0] = malloc(sizeof(char));

	char ch = ' ', prev_ch = ' ';

	while ((ch = fgetc(fptr)) != EOF)
	{
		//prev_ch = ch;
		//ch = getchar();
		//ioChecker(stdin);
		//eof = feof(stdin);
		//wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*)); // Allocate wordlist[row]
		//memAllocChecker(wordlist);
		//wordlist[row] = malloc(sizeof(char)); // Allocate wordlist[row][0]
		//memAllocChecker(wordlist[row]);
		//if (!eof && prev_ch !=0)
		//{
		////word[buffSize++] = ch;
		//col++;
		//}


		if (ch == ' ')
		{
			row++;
			wordlist = (char**)realloc(wordlist, (row + 1) * sizeof(char*));
			memAllocChecker(wordlist);
			wordlist[row] = malloc(sizeof(char));
			memAllocChecker(wordlist);
			col = 0;
			//counter++;
		}

		/*if (word == NULL)
		{
		word = (char**)malloc(word,(rowsizeof(char));
		memAllocChecker(word);
		}*/

		else
		{
			wordlist[row][col] = ch; //  <-------------------------------------------------
									 //counter++;
			col++;
			wordlist[row] = realloc(wordlist[row], (col + 1) * sizeof(char)); // <------------------------
			memAllocChecker(wordlist);
			//wordlist[row][col] = ' ';

			/*word = (char*)realloc(word, (col + 1) * sizeof(char));
			memAllocChecker(word);*/

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

	/*for (int j = 0; j < row; j++)
	{
	for (int i = 0; i < col && col != ' '; i++)
	{
	putc(wordlist[i][j], stdout);
	}
	putc('\n', stdout);

	free(wordlist[j]);

	}*/
	free(wordlist);
	fptr = NULL;
	//free(word);
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
		/*while (*a == '\0')
		a++;

		while (*b == '\0')
		b++;*/

		if (*a == *b)
			return 0;

		if (*a == SPACE && *b == SPACE)
			return 0;

		if ((*a ^ 42) < (*b ^ 42))
			return -1;

		if (*a == SPACE && *b != SPACE) //*a ran out first
			return -1;

		if ((*a ^ 42) > (*b ^ 42))
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

int FROBCMP(const void * a, const void * b)
{
	const char * i1 = *(const char**)a;
	const char * i2 = *(const char**)b;
	return frobcmp(i1, i2);
}
