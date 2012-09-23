#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	lex("target.txt", "key.txt", "mapped.txt");
	s = targetFile_read("mapped.txt");
	split = splitByDelim(s, delim);

	char *pattern = "((?:[a-z][a-z0-9_]*))(\\s*)(\\()(\\s*)(.*)(\\s*)(\\))";
	char *stub = targetFile_read("./stub/stub.c");
	int count = 0;

	for (; count < tokenized; count++) {
		split[count] = trimwhitespace(split[count]);
		regexStr restr = regexMatch(pattern, trimwhitespace(split[count]));
		strcat(stub, restr.substr[METHOD]);
		strcat(stub, "(");
	        strcat(stub, restr.substr[PARAM]);
	        strcat(stub, ");\n");
	}

	strcat(stub, "return 0;\n}");

	targetFile_write("gen.c", stub);
	system("gcc gen.c -o obj/gen helpers.h");
	system("obj/gen");
	
	return 0;
}
