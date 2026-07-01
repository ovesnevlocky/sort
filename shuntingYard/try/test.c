#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "token.h"

void printMem(var tmp)
{

	if(tmp.tag == UNINICIALIZED)
		printf("uninicialized\n");

	if(tmp.tag == INT)
	{
		printf("popped: %i\n", tmp.data.var);
	}
	else if(tmp.tag == CHAR)
	{
		printf("popped: %c\n", tmp.data.operand);
	}
}

void testStackPushPop()
{
	Stack s;

	stackInit(&s);

	var tmpi = {0};
	var tmpc = {0};
	var ret = {0};

	tmpc.tag = CHAR;
	tmpi.tag = INT; 

	int i = 0;
	char ch = 'a';
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//0
	
	ret = stackPop(&s);
	//
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//1

	ret = stackPop(&s);
	//-	

	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 3 
	ret = stackPop(&s);
	//2
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 4
	
	ret = stackPop(&s);
	//2
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 6
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 6 7
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 6 7 8
	ret = stackPop(&s);

	ret = stackPop(&s);
	//2 5 6
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 6 9


	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 6 9 10
	
	tmpi.data.var = i;
	i++;
	stackPush(&s, tmpi);
	//2 5 6 9 10 11


	while(!isStackEmpty(&s))
	{
		ret = stackPop(&s);

		printMem(ret);	
	}
		

}

void testStack()
{
	Stack s;

	stackInit(&s);

	char ch = 'a';


	var tmp  = stackPop(&s);

	if(tmp.tag == UNINICIALIZED)
		printf("ok\n");
	else
		printf("not ok\n");

	for(int i = 0; i < 3 ; i++)
	{
		tmp.tag = INT;
		tmp.data.var = i;
		
		stackPush(&s, tmp);
	}

	while(!isStackEmpty(&s))
	{
		tmp = stackPop(&s);

		printMem(tmp);	
	}

	for(int i = 0; i < 3; i++)
	{
		tmp.tag = CHAR;
		tmp.data.var = ch;
		ch++;
		stackPush(&s, tmp);
	}

	while(!isStackEmpty(&s))
	{
		tmp = stackPop(&s);
		printMem(tmp);
	}

	for(int i = 0; i < 120 ; i++)
	{
		tmp.tag = INT;
		tmp.data.var = i;
		
		stackPush(&s, tmp);
	}

	while(!isStackEmpty(&s))
	{
		tmp = stackPop(&s);
		printMem(tmp);
	}

	for(int i = 0; i < 13; i++)
	{
		tmp = stackPop(&s);
		printMem(tmp);
	}
	

	stackPop(&s);

	if(tmp.tag == UNINICIALIZED)
		printf("ok\n");
	else
		printf("not ok\n");

}


void testQueue()
{
	Queue q;

	char ch = 'a';
	queueInit(&q);
	var tmp = popQueue(&q);
	

	for(int i = 0; i <3  ; i++)
	{
		tmp.tag = INT;
		tmp.data.var = i;
		pushQueue(&q, tmp);
	}

	while(!isQueueEmpty(&q))
	{
		tmp = popQueue(&q);
		printMem(tmp);
	}

	for(int i = 0; i < 5 ; i++)
	{
		tmp = popQueue(&q);
		printMem(tmp);
	}
	


	if(tmp.tag == UNINICIALIZED)
		printf("ok\n");
	else
		printf("not ok\n");

	for(int i = 0; i < 4 ; i++)
	{
		tmp.tag = INT;
		tmp.data.var = i;
		pushQueue(&q, tmp);
	}

	while(!isQueueEmpty(&q))
	{
		tmp = popQueue(&q);
		printMem(tmp);
	}

}


void testQueuePushPop()
{
	Queue q;
	queueInit(&q);

	var tmp = {0};
	var ret = {0};

	tmp.tag = INT; 
	int i = 0;
	char ch = 'a';
	
	
	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	//0

	ret = popQueue(&q);
	//-
	

	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	//1 2 3
	


	ret = popQueue(&q);
	//2 3
	

	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	//2 3 4
	
	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	//2 3 4 5

	tmp.data.var = i;
	pushQueue(&q, tmp);
	i++;
	//2 3 4 5 6
	


	ret = popQueue(&q);
	while(!isQueueEmpty(&q))
	{
		tmp = popQueue(&q);
		printMem(tmp);
	}

	for(int i = 0; i < 9; i++)
	{
		tmp.data.var = i;
		pushQueue(&q, tmp);
	}

	while(!isQueueEmpty(&q))
	{
		tmp = popQueue(&q);
		printMem(tmp);
	}


}
