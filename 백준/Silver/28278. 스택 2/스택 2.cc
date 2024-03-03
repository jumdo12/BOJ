#include <iostream>

class Stack{
    int top;
    int arr[1000000];

    public:
    Stack();
    void push(int item);
    int pop();
    int size();
    int is_empty();
    int peak();
};

Stack::Stack(){
    top = -1;
}

void Stack::push(int item){
    arr[++top] = item;
}

int Stack::pop(){
    if(is_empty()){
        return -1;
    }
    return arr[top--];
}

int Stack::size(){
    return top+1;
}

int Stack::is_empty(){
    return top == -1;
}

int Stack::peak(){
    if(is_empty())  return -1;
    return arr[top];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N,num,X;
    Stack s;
    
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>num;
        if(num == 1){
            std::cin>>X;
            s.push(X);
        }
        else if(num == 2){
            std::cout<<s.pop()<<'\n';
        }
        else if(num == 3){
            std::cout<<s.size()<<'\n';
        }
        else if(num == 4){
            std::cout<<s.is_empty()<<'\n';
        }
        else{
            std::cout<<s.peak()<<'\n';
        }
    }

    return 0;
}