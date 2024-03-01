#include <iostream>
#include <map>
#include <string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::map<std::string,int> m;
    int N,M,cnt=0;
    std::string str;
    std::cin>>N>>M;
    for(int i=0; i<N; i++){
        std::cin>>str;
        m.insert({str,1});
    }
    for(int i=0; i<M; i++){
        std::cin>>str;
        if(m.find(str) != m.end())  cnt++;
    }
    std::cout<<cnt;
    return 0;
}