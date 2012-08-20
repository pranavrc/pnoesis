#ifndef LOOPER_H
#define LOOPER_H

#include <stdio.h>
#include <malloc.h>
#include "lexMap/keyMapper.h"

struct paramTypes {
	int numbers;
	char *words;
};

typedef void *(*sequencerArray)(struct paramTypes);

void say(struct paramTypes stuffToSay);

#endif
