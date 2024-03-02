#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::map<int,int> m;
    int N,temp;
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>temp;
        m[temp]++;
    }
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>temp;
        std::cout<<m[temp]<<" ";
    }
    return 0;
}