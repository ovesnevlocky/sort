#include <stdio.h>


typedef enum varType
{
	UNINICIALIZED = 0,
	INT = 10,
	CHAR = 11
}varType;


typedef struct 
{
	varType tag;
	union
	{
		int var;
		char operand;
	}data;
}var;



void printMem(var *a)
{

	if(a->tag == INT)
	{
		printf("%i\n", a->data.var);
	
	}
	else if(a->tag == CHAR)
	{
		printf("%c\n", a->data.operand);
	}



}
int main()
{
	var arr[10] = {0};

	var a;
	a.tag = INT;
	a.data.var = 1234;
	
	printMem(&a);


	var b;
	b.tag = CHAR;
	b.data.operand = '*';

	printMem(&b);

}
