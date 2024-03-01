#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::map<int,int> m;
    int N,M,temp;
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>temp;
        m.insert({temp,1});
    }
    std::cin>>M;
    for(int i=0; i<M; i++){
        std::cin>>temp;
        if(m.find(temp) != m.end()) std::cout<< 1 << " ";
        else    std::cout<<0<<" ";
    }

    return 0;
}