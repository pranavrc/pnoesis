#include "looper.h"

sequencerArray * sequencer;

void say(struct paramTypes stuffToSay)
{
	printf("%s\n", stuffToSay.words);
}

int main(void)
{
	struct paramTypes reply;
	char *str = "Hello World!";
	
	reply.words = str;

	sequencer = malloc(sizeof(sequencer));
	sequencer[0] = say;
	(sequencer[0])(reply);

	free(sequencer);

	return 0;
}
