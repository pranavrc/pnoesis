#include "regex.h"

int tokenized = 0;

/* Returning a struct as part of a bad hack to get around pointer traversal issues. TODO: Dynamic mem alloc */
regexStr regexMatch(char *re, char *txt)
{
	const char *error;
	int erroffset;
	int ovector[186];
	int substrCount;
	regexStr t;

	pcre *r =  pcre_compile(re, PCRE_CASELESS|PCRE_DOTALL, &error, &erroffset, NULL);
	int rc = pcre_exec(r, NULL, txt, strlen(txt), 0, 0, ovector, 186);
	//printf("%d\n", rc);

	if (rc > 0) {
		for (substrCount = 1; substrCount <= rc; substrCount++) {
			pcre_copy_substring(txt, ovector, rc, substrCount, t.substr[substrCount - 1], 1024);
		}
	}

	free(r);
	return t;
}

char **splitByDelim(char *str, char delim[])
{
	char *result = NULL;
	char **components;
	int count = 0;
	components = malloc(sizeof(char*));
	result = strtok(str, delim);

	while (result != NULL) {
		components = realloc(components, (strlen(result) + 1) * sizeof(char*));
		components[count] = result;
		count++;
		result = strtok(NULL, delim);
		tokenized++;
	}

	return components;
}

char *trimwhitespace(char *str)
{
  	char *end;

        // Trim leading space
        while(isspace(*str)) str++;

        if(*str == 0)  // All spaces?
        return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while(end > str && isspace(*end)) end--;

	// Write new null terminator
	*(end+1) = 0;

	return str;
}

/*int main(void)
{
	char str[] = "say \"string\", say \"foo\", say";
	char delim[] = ",";
	char **components;
	components = splitByDelim(str, delim);
	char *pattern = "((?:[a-z][a-z0-9_]*))(\\s+)(\".*?\")";
	regexStr restr = regexMatch(pattern, components[0]);

	printf("\n[%s]\n", trimwhitespace(components[1]));
	printf("\n[%s]\n", restr.substr[2]);

	return 0;
}*/
