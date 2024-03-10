#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <utility>

bool comp(std::pair<std::string ,int> p1, std::pair<std::string,int> p2){
    if(p1.second == p2.second){
        if(p1.first.length() == p2.first.length())  return p1.first < p2.first;
        else    return p1.first.length() > p2.first.length();
    }
    else    return p1.second > p2.second;
}

int main(){
    int N,M;
    std::string str;
    std::map<std::string,int> m;
    std::vector<std::pair<std::string,int>> v;

    std::cin>>N>>M;
    while(N--){
        std::cin>>str;
        if(str.length() < M)    continue;
        m[str]++;
    }

    for(auto it : m){
        v.push_back({it.first,it.second});
    }
    std::sort(v.begin(),v.end(),comp);

    for(auto it : v){
        std::cout<<it.first<<'\n';
    }

    return 0;
}