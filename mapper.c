#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lexMap/keyMapper.h"
#include "regex.h"

#define METHOD 0
#define PARAM 4

int tokenized;

int main(int argc, char *argv[])
{
	char **split;
	char delim[] = ",\n";
	
	char *s;
	//s = malloc(sizeof(char*));
	s = lex("target.txt", "key.txt", "mapped.txt");
	//printf("%s\n", s);
	split = splitByDelim(s, delim);

	char *pattern = "((?:[a-z][a-z0-9_]*))(\\s*)(\\()(\\s*)(.*)(\\s*)(\\))";

	//char *stub = targetFile_read("key.txt");

	//printf("%s", stub);

	/*printf("\n[%s]\n", restr.substr[4]);
	printf("%s\n", trimwhitespace(split[4]));
	printf("\n%d\n", tokenized);*/

	int count = 0;

	for (; count < tokenized; count++) {
		printf("\n%d\n", count);
		printf("%s\n", split[count]);
		split[count] = trimwhitespace(split[count]);
		printf("%s\n", split[count]);
		regexStr restr = regexMatch(pattern, trimwhitespace(split[count]));
		//printf("%s\n", restr.substr[4]);
		//strcat(stub, restr.substr[0]);
		//strcat(stub, "(");
	        //strcat(stub, restr.substr[4]);
	        //strcat(stub, ");\n");
	}

	//strcat(stub, "return 0;\n}");

	//printf("\n%s\n", stub);
	
	free(s);
	
	return 0;
}
