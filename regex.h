#ifndef REGEX_H
#define REGEX_H

#include <stdio.h>
#include <string.h>
#include <pcre.h>

#define REGEXMATCHES 4

typedef struct {
	char substr[REGEXMATCHES][1024];
} regexStr;

regexStr regexMatch(char *re, char *txt);

#endif
