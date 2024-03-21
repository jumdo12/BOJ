#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
int stack[MAX_SIZE], input[MAX_SIZE], top = -1;
char output[2 * MAX_SIZE];

void push(int item){
    stack[++top] = item;
}

void pop(){
    top--;
}

int peak(){
    return stack[top];
}

int main(){
    int N, idx = 0 , temp = 1;
    scanf("%d" , &N);
    for(int i=0; i<N; i++){
        scanf("%d" , &input[i]);
        while(input[i] > peak() || top == -1){
            push(temp++);
            output[idx++] = '+';
        }
        if(input[i] == peak()){
            pop();
            output[idx++] = '-';
        }
        else{
            printf("%s" , "NO");
            return 0;
        }
    }

    for(int i=0; i<2*N; i++){
        printf("%c\n" , output[i]);
    }

    return 0;
}