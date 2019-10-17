
#include "stdio.h"
#include <string.h>



/*       Stack Implementation            */

bool StackFull(char S[], int top, int len)
{
	return (top == len - 1);
}

bool StackEmpty(char S[], int top)
{
	return (top == -1);
}

void Push(char S[], int& top, int len, char in_chr)
{
	if (StackFull(S, top, len))
		return; //error - overflow
	top++;
	S[top] = in_chr;
}

char Pop(char S[], int& top)
{
	if (StackEmpty(S, top))
		return ' '; //error - underflow
	char result = S[top];
	top--;
	return result;
}

int main()
{
	//use const

	//Define Stack
	char S[10];
	int top = -1;
	int len = 10;

	bool res1 = StackEmpty(S, top);



	for (int i = 0; i < 5; i++) {
		Push(S, top, len, 's');
		char chr = Pop(S, top);
		printf("%c ", chr);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		char chr = Pop(S, top);
		printf("%c ", chr);
	}
	printf("\n");



	bool res2 = StackEmpty(S, top);
	printf("%s", res2 ? "true" : "false");
	if (res1 && !res2)
		printf("all is good");
	getchar();
	return 0;
}
