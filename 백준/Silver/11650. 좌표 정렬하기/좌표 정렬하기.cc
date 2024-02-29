#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<std::pair<int,int>> v;
    int N,x,y;
    std::cin>>N;
    for(int i=0; i<N;i++){
        std::cin>>x>>y;
        v.push_back({x,y});
    }
    std::sort(v.begin(),v.end());
    for(int i=0; i<N; i++){
        std::cout<<v[i].first<<" "<<v[i].second << '\n';
    }
    return 0;
}