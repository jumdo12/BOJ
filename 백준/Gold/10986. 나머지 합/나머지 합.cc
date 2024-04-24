#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    
    long long cnt[1001] = {0};
    long long N,M,temp,sum=0,ans = 0;
    std::cin>>N>>M;
    
    for(int i=0; i<N; i++){
        std::cin>>temp;
        sum += temp;
        cnt[sum % M]++;
    }
    
    for(int i=0; i<=M; i++){
        ans += (cnt[i] * (cnt[i]-1)) / 2;
    }
    
    ans += cnt[0];
    
    std::cout<<ans;
    
    return 0;
}