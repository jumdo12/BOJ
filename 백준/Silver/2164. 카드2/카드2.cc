#include <iostream>
#include <queue>

int main(){
    int N,temp;
    std::queue<int> q;
    std::cin>>N;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    temp = q.front();
    while(q.size()!= 1){
        q.pop();
        temp = q.front();
        if(q.size() == 1){
            break;
        }
        q.push(temp);
        q.pop();
    }
    printf("%d",temp);
    return 0;
}