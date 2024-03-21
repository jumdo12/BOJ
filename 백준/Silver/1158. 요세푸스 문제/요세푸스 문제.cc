#include <iostream>
#include <vector>

int main(){
    int N,K,curr=0;
    std::vector<int> v;

    std::cin>>N>>K;
    for(int i=1; i<=N; i++){
        v.push_back(i);
    }

    std::cout<<"<";
    while(N--){
        curr = (curr + K - 1 ) % v.size();
        std::cout<<v[curr];
        if(v.size() != 1){
            std::cout<<", ";
        }
        v.erase(v.begin() + curr);
    }
    std::cout<<">";

    return 0;
}