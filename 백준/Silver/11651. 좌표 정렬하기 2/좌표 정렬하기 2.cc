#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(std::pair<int,int> p1, std::pair<int,int>p2){
    if(p1.second == p2.second)  return p1.first < p2.first;
    else    return p1.second < p2.second;
}

int main(){
    int N;
    std::vector<std::pair<int,int>> v;
    std::cin>>N;
    for(int i=0; i<N; i++){
        int x,y;
        std::cin>>x>>y;
        v.push_back({x,y});
    }
    std::sort(v.begin(),v.end(),cmp);
    for(int i=0; i<N; i++){
        std::cout<<v[i].first<<" "<<v[i].second<<'\n';
    }
    return 0;
}          