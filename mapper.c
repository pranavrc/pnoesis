#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lexMap/keyMapper.h"

/*typedef struct {
	char **routines;
	char **parameters;
} interpreted;

interpreted stringParse(char *source, char *deLim)
{
	strtok()
}*/

int main(int argc, char *argv[])
{
	char *s;
	s = lex("target.txt", "key.txt", "mapped.txt");
	printf("%s", s);

	return 0;
}
