#include <stdlib.h>

typedef struct node {
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct queueType {
	NodePtr head, tail;
} QueueType, *Queue;

Queue initQueue() {
	Queue qp = (Queue) malloc(sizeof(QueueType));
	qp -> head = NULL;
	qp -> tail = NULL;
	return qp;
} //end initQueue

int empty(Queue Q) {
	return (Q -> head == NULL);
} //end empty

void enqueue(Queue Q, QueueData d) {
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> data = d;
	np -> next = NULL;
	if (empty(Q)) {
		Q -> head = np;
		Q -> tail = np;
	}
	else {
		Q -> tail -> next = np;
		Q -> tail = np;
	}
} //end enqueue

QueueData dequeue(Queue Q) {
	if (empty(Q)) {
		printf("\nAttempt to remove from an empty queue\n");
		exit(1);
	}
	QueueData hold = Q -> head -> data;
	NodePtr temp = Q -> head;
	Q -> head = Q -> head -> next;
	if (Q -> head == NULL) Q -> tail = NULL;
	free(temp);
	return hold;
} //end dequeue
