#ifndef REGEX_H
#define REGEX_H

#include <stdio.h>
#include <string.h>
#include <pcre.h>
#include <ctype.h>

#define REGEXMATCHES 10

typedef struct {
	char substr[REGEXMATCHES][1024];
} regexStr;

regexStr regexMatch(char *re, char *txt);
char **splitByDelim(char str[], char delim[]);
char *trimwhitespace(char *str);
extern int tokenized;

#endif
