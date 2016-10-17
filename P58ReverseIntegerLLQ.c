// Program P5.8

#include <stdio.h>
typedef struct {
	int num;
} QueueData;
#include <queue.h>

main() {
	int n;
	QueueData temp;
	Queue Q = initQueue();
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	while (n > 0) {
		temp.num = n % 10;
		enqueue(Q, temp);
		n = n / 10;
	}
	printf("\nDigits in reverse order: ");
	while (!empty(Q))
		printf("%d", dequeue(Q).num);
	printf("\n");
} //end main
