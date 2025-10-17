#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdbool.h>
#define max_size 20000
int o = 0;
typedef struct {
	int data[max_size];
	int front;
	int rear;
}stack;

bool isempty(stack* S) {
	if (S->front == S->rear) return 1;
	else return 0;
}

void push(stack* S, int n) {
	S->data[S->rear] = n;
	S->rear++;
}

int pop(stack* S, int P[]) {
	if (isempty(S)) {
		o++;
		return -1;

	}
	P[o] = S->data[S->front];
	o++;
	S->front++;
	return 1;
}

void chushihua(stack* S) {
	S->front = 0;
	S->rear = 0;

}
int main()
{
	stack S;
	chushihua(&S);
	int m, n, num, k;
	k = 0;
	int popnum[20000];
	int istrue[20000];
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		if (num == 1) {
			scanf("%d", &n);
			push(&S, n);
		}
		if (num == 0) {
			istrue[k] = pop(&S, popnum);
			k++;
		}
	}
	for (int i = 0; i <= o; i++) {
		if (istrue[i] == -1) {
			printf("invalid\n");
		}
		if (istrue[i] == 1) {
			printf("%d\n", popnum[i]);
		}
	}

}