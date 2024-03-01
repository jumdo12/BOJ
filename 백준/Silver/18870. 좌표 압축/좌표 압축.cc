#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;
    std::vector<int> v,sorted;
    for(int i=0; i<N; i++){
        int temp;
        std::cin>>temp;
        v.push_back(temp);
        sorted.push_back(temp);
    }

    std::sort(sorted.begin(),sorted.end());
    sorted.erase(std::unique(sorted.begin(),sorted.end()),sorted.end());

    for(int i=0; i<N; i++){
        auto it = std::lower_bound(sorted.begin(),sorted.end(),v[i]);
        std::cout<<it - sorted.begin()<< " ";
    }

    return 0;
}