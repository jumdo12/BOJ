#include <stdio.h>

typedef struct{
    int data[10000002];
    int top;
}StackType;

void init(StackType *s){
    s -> top = -1;
}

int is_empty(StackType *s){
    return s -> top == -1;
}

int peek(StackType *s){
    return s -> data[s -> top];
}

void push(StackType *s , int n){
    s -> data[++(s -> top)] = n;
}

int pop(StackType *s){
    return s -> data[s->top--];
}

int main(){
    int data[10000002];
    int res[10000002];
    int n; scanf("%d",&n);
    StackType s;
    init(&s);

    for(int i=0; i<n; i++){
        scanf("%d", &data[i]);
    }

    for(int i=n-1; i>=0; i--){
        if(is_empty(&s)){
            push(&s,data[i]);
            res[i] = -1;
        }
        else{
            if(peek(&s) <= data[i]){
                while(!is_empty(&s) && peek(&s) <= data[i]){
                    pop(&s);
                }
                if(is_empty(&s)){
                    res[i] = -1;
                }
                else{
                    res[i] = peek(&s);
                }
            }
            else{
                res[i]=peek(&s);
            }
            push(&s,data[i]);
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ",res[i]);
    }

    return 0;
}