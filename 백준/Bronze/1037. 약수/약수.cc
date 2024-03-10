#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int N,A;
    std::vector<int> v;
    std::cin>>N;
    while(N--){
        std::cin>>A;
        v.push_back(A);
    }
    std::sort(v.begin(),v.end());
    std::cout<<v[0]*v[v.size()-1];
    return 0;
}