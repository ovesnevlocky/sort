#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX_SIZE 100


#include "stdbool.h"
#include "token.h"

typedef struct
{
	var arr[MAX_SIZE];
	int head;
	int tail;
	int count;
}Queue;


void printhai();


void queueInit(Queue *q);

bool isQueueEmpty(Queue *q);

bool isQueueFull(Queue *q);

bool enqueue(Queue *q, var a);

bool dequeue(Queue *q);

var peek(Queue *q);


#endif


