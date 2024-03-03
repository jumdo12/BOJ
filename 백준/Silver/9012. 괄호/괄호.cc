#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init(StackType *s){
    s -> top = -1;
}

void push(StackType *s , int item){
    if(s -> top == MAX_STACK_SIZE -1){
        return;
    }
    s -> stack[++(s -> top)] = item;
}

int is_empty(StackType *s){
    return (s -> top == -1);
}

element pop(StackType *s){
    if(is_empty(s)){
        return ' ';
    }
    return (s -> stack[s -> top--]);
}

int check(const char* str){
    StackType *s = (StackType*)malloc(sizeof(StackType));
    init(s);
    int len = strlen(str);
    char temp;
    for(int i=0; i<len; i++){
        temp = str[i];
        if(temp == '('){
            push(s , temp);
        }
        else if(temp == ')'){
            if(is_empty(s)){
                return 0;
            }
            pop(s);
        }
    }
    if(!is_empty(s)){
        return 0;
    }
    return 1;
    free(s);
}

int main(){
    int N;
    char str[100];
    scanf("%d" , &N);
    for(int i=0; i<N; i++){
        scanf("%s" , str);
        if(check(str)){
            printf("%s" , "YES");
        }
        else{
            printf("%s" , "NO");
        }
        printf("\n");
    }
    return 0;
}