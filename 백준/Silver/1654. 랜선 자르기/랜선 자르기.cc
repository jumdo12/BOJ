#include <iostream>
#include <algorithm>
#include <vector>

unsigned max(unsigned a, unsigned b){
    return a > b ? a : b;
}

int main(){
    unsigned int N,K,tmp;
    unsigned left,right;
    unsigned cnt;
    unsigned ans;

    std::vector<unsigned> v;

    std::cin>>K>>N;
    for(int i=0; i<K; i++){
        std::cin>>tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(),v.end());

    ans = 0;
    left = 1;
    right = v[v.size()-1];

    while(left <= right){
        unsigned mid = (left + right) / 2;
        cnt = 0;

        for(int i=0; i<v.size(); i++){
            cnt += (v[i] / mid);
        }

        if(cnt >= N){
            left = mid + 1;
            ans = max(ans,mid);
        }
        else{
            right = mid - 1;
        }
    }

    std::cout<<ans;
    return 0;
}