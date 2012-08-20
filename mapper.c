#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lexMap/keyMapper.h"

int main(int argc, char *argv[])
{
	lex("target.txt", "key.txt", "mapped.txt");

	return 0;
}
