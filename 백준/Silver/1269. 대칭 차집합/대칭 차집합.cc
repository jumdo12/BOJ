#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::map<int,int> m;

    int N,M,num,cnt=0;
    std::cin>>N>>M;
    for(int i=0; i<N; i++){
        std::cin>>num;
        m[num]++;
    }
    for(int i=0; i<M; i++){
        std::cin>>num;
        m[num]++;
    }

    for(auto it : m){
        if(it.second == 1) cnt++;
    }   
    std::cout<<cnt++;
    return 0;
}