/*
For this laboratory, you will implement transliteration programs tr2b and tr2u that use buffered and unbuffered
I/O respectively, and compare the resulting implementations and performance. Each implementation should be a
main program that takes two operands from and to that are byte strings of the same length, and that copies
standard input to standard output, transliterating every byte in from to the corresponding byte in to.
Your implementations should report an error from and to are not the same length, or if from has duplicate bytes.
To summarize, your implementations should like the standard utility tr does, except that they have no options,
characters like [, - and \ have no special meaning in the operands, operand errors must be diagnosed, and your
implementations act on bytes rather than on (possibly multibyte) characters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

int main(int argc, const char * argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "%s", "Error. Wrong number of arguments. Exiting program.\n");
		exit(1);
	}

	char * from = argv[1];
	char * to = argv[2];


	//checking if lengths aren't the same:
	if (strlen(from) != strlen(to))
	{
		fprintf(stderr, "%s", "Error. The lengths are not the same. Exiting program.\n");
		exit(1);
	}

	//checking for duplicates:
	int i = 0;
	for (0; i < strlen(from); i++)
	{
		int j = i + 1;
		for (j; j < strlen(from); j++)
		{
			if (from[i] == from[j])
			{
				fprintf(stderr, "%s", "Error. Duplicate characters. Exiting program.\n");
				exit(1);
			}
		}
	}

	//Taking inputs from stdin
	char c;
	read(0, &c,1);
	while (c != EOF)
	{

		for (int i = 0; i < strlen(from); i++)
		{
			if (c == from[i])
			{
				c = to[i];
				write(0,&c,1);
				continue;
			}
		}
		read(1, &c, 1);
	}
	exit(1);
}