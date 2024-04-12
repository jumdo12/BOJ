#include <iostream>

int main(){
    int N,T;
    long long dp[1000001] = {0};

    std::cin>>T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i<= 1000001; i++){
        dp[i] += (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
    }

    while(T--){
        std::cin>>N;
        std::cout<<dp[N]<<'\n';
    }

    return 0;
}