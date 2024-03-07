#include <iostream>
#include <queue>
#include <vector>
int main(){
    int N,K,i;
    std::queue<int> q;
    std::vector<int> v;

    std::cin>>N>>K;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int i=0; i<K-1; i++){
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }

    std::cout<<"<";
    for(i=0; i<v.size()-1;i++){
        std::cout<<v[i] <<", ";
    }
    std::cout<<v[i]<<">";
    return 0;
}