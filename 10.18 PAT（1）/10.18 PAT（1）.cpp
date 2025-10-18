#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int youxianjii(char c) {
	switch (c) {
	case('<'): return 1;
	case('('): return 2;
	case('['): return 3;
	case('{'): return 4;
		default: return 0;
	}
}

int if_match(char prv, char nex) {
	if (prv == '<' && nex == '>') return 1;
	if (prv == '(' && nex == ')') return 1;
	if (prv == '[' && nex == ']') return 1;
	if (prv == '{' && nex == '}') return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	char stack_c[1001];
	int youxianji[1001];
	int top = -1;
	char prv, nex;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		char tmp[1001];
		scanf("%s", tmp);
		top = -1;
		for (int k = 0; tmp[k] != '\0'; k++) {
			prv = tmp[k];
			if (prv == '{' || prv == '<' || prv == '[' || prv == '(') {
				top++;
				stack_c[top] = prv;
				youxianji[top] = youxianjii(prv);
				if (top != 0) {
					if(youxianji[top] > youxianji[top - 1]){
						flag = 0;
						break;
					}
				}
			}
			if (prv == '}' || prv == '>' || prv == ']' || prv == ')') {
				if (top == -1 || stack_c[top] != prv) {
					flag = 0;
					break;
				}
				if (stack_c[top] == prv) {
					flag = 1;
					top--;
				}
				
			}
			
		}
		if (flag == 1) {
			printf("Match\n");
		}
		if (flag == 0) {
			printf("Fail\n");
		}
		
	}

    return 0;
}