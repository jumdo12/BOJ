#include <iostream>
#include <map>
#include <string>
#include <vector>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::string name;
    std::map<std::string,int> m;
    std::vector<std::string> v;
    std::cin>>N>>M;
    for(int i=0; i<N; i++){
        std::cin>>name;
        m.insert({name,i+1});
        v.push_back(name);
    }
    for(int i=0; i<M; i++){
        std::cin>>name;
        if(name[0] <= '9' && name[0] >= '0'){
            int temp = std::stoi(name);
            std::cout<<v[temp-1] <<'\n';
        }
        else{
            auto it = m.find(name);
            std::cout<<it->second<<'\n';
        }
    }
    return 0;
}