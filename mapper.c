#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lexMap/keyMapper.h"
#include "regex.h"

int main(int argc, char *argv[])
{
	char **split;
	char delim[] = ",";
	char *s;
	s = malloc(sizeof(char*));
	s = lex("target.txt", "key.txt", "mapped.txt");
	printf("%s\n", s);
	split = splitByDelim(s, delim);
	printf("%s\n", trimwhitespace(split[0]));

	return 0;
}
