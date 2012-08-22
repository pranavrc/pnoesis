#include "regex.h"

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
	printf("%d\n", rc);

	if (rc > 0) {
		for (substrCount = 1; substrCount <= rc; substrCount++) {
			pcre_copy_substring(txt, ovector, rc, substrCount, t.substr[substrCount - 1], 1024);
		}
	}

	//printf("(%s)(%s)(%s)(%s)\n", t.substr[0], t.substr[1], t.substr[2], t.substr[3]);

	return t;
}

int main(void)
{
	char *str = "say \"string\"";
	char *pattern = "((?:[a-z][a-z0-9_]*))(\\s+)(\".*?\")";
	regexStr restr = regexMatch(pattern, str);

	printf("\n[%s]\n", restr.substr[2]);


	//free(restr);

	return 0;
}
