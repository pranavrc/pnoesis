#include <stdio.h>
#include <malloc.h>

struct dataStruct {
    int intData;
    char *charData;
};

typedef void *(*our_function_ptr)(struct dataStruct);

our_function_ptr *funcArray;

int func1(struct dataStruct param) {
    return param.intData;
}

char *func2(struct dataStruct param) {
    return param.charData;
}

void sequencer(our_function_ptr * foo, struct dataStruct param)
{
	int i;
	int j;
	char *k;

	printf("%d\n", sizeof(foo));
	printf("%d\n", sizeof(void *));
	printf("%d\n", sizeof(foo)/sizeof(foo[0]));

	for (i = 0; i <= sizeof(foo)/sizeof(void *); i++) {
		if (i == 0) { 
			j = (int)((foo[i])(param));
			printf("%d\n", j);
		}
		if (i == 1) {
			k = (char *)((foo[i])(param));
			printf("%s\n", k);
		}
	}
}

void looper(our_function_ptr * foo, iterationCount)
{

		
int main(void)
{
    int a;
    char *b;
 
    struct dataStruct c;
        
    c.intData = 1000;
    c.charData = "foobar";

    funcArray = malloc(2 * sizeof(funcArray));

    funcArray[0] = (our_function_ptr) func1;
    funcArray[1] = (our_function_ptr) func2;

    //a = (int)((funcArray[0])(c));
    //b = (char *)((funcArray[1])(c));
    
    sequencer(funcArray, c);

    free(funcArray);

    //printf("%d\n", a);
    //printf("%s\n", b);

    return 0;
}
