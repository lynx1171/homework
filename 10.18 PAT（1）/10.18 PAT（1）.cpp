#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const int maxm = 1e5 + 10;

void buildNext(char* P, int next[], int m) {
    int k = next[0] = -1;
    for (int j = 0; j < m - 1; j++) {
        while (k >= 0 && P[k] != P[j])
            k = next[k];
        next[j + 1] = ++k;
    }
}

int KMP(char* S, char* P, int n, int m) {
    int next[maxm], i = 0, j = 0;
    buildNext(P, next, m);
    while (j < m && i < n) {
        if (j == -1 || S[i] == P[j]) i++, j++;
        else j = next[j];
    }
    return (j == m) ? i - m : -1;
}

int main() {
    char s[100001], p[100001];
    scanf("%s", s);
    scanf("%s", p);
    int n = strlen(s);
    int m = strlen(p);
    int next[maxm];
    buildNext(p, next, m);
    int num1 = m / 4;
    int num2 = 2 * m / 4;
    int num3 = 3 * m / 4;
    printf("%d %d %d \n", next[num1], next[num2], next[num3]);
    int a = KMP(s, p, n, m);
    printf("%d", a);
    return 0;
}