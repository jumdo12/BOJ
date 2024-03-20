#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX_LEN 1001
 
int main() {
    int T, t, i, j;
    scanf("%d ", &T);
    char string[MAX_LEN];
    char stack[21];
    int top = 0, len;
 
    for (t = 0; t < T; t++) {
        fgets(string, MAX_LEN, stdin);
        len = strlen(string);
        for (i = 0; i < len - 1; i++) {
            if (string[i] != ' ')
                stack[top++] = string[i];
 
            if (string[i] == ' ' || i == len - 2) {
                for (j = top - 1; j >= 0; j--)
                    printf("%c", stack[j]);
                printf(" ");
                top = 0;
            }
        }
        printf("\n");
    }
    return 0;
}