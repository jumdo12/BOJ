#include <iostream>
#include <queue>

int main(){
    int N;
    std::queue<int> q;
    std::cin>>N;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(q.size()!= 1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    printf("%d",q.front());
    return 0;
}