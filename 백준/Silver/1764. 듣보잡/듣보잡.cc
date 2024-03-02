#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::string str;
    std::map<std::string,int> m;
    std::vector<std::string> v;
    std::cin>>N>>M;
    for(int i=0; i<N; i++){
        std::cin>>str;
        m.insert({str,1});
    }
    for(int i=0; i<M; i++){
        std::cin>>str;
        if(m[str] == 1){
            v.push_back(str);
        }
    }
    std::sort(v.begin(),v.end());
    std::cout<<v.size()<<'\n';
    for(int i=0; i<v.size();i++){
        std::cout<<v[i]<<'\n';
    }
    return 0;
}