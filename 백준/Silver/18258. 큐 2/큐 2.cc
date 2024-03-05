#include <iostream>
#include <string>
class Queue{
    int data[2000001];
    int front,rear;

    public:
    Queue();
    void push(int item);
    int pop();
    int size();
    int empty();
    int Front();
    int back();
};

Queue::Queue(){
    front = rear = -1;
}
void Queue::push(int item){
    data[++rear]=item;
}
int Queue::pop(){
    if(empty()) return -1;
    return data[++front];
}
int Queue::size(){
    return rear - front;
}
int Queue::empty(){
    return (front == rear);
}
int Queue::Front(){
    if(empty()) return -1;
    return data[front + 1];
}
int Queue::back(){
    if(empty()) return -1;
    return data[rear];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Queue q;
    int N;
    std::string str;
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>str;
        if(str=="push"){
            int temp;
            std::cin>>temp;
            q.push(temp);
        }
        else if(str=="pop"){
            std::cout<<q.pop()<<'\n';
        }
        else if(str=="size"){
            std::cout<<q.size()<<'\n';
        }
        else if(str=="empty"){
            std::cout<<q.empty()<<'\n';
        }
        else if(str=="front"){
            std::cout<<q.Front()<<'\n';
        }
        else if(str=="back"){
            std::cout<<q.back()<<'\n';
        }
    }
    return 0;
}