#include <iostream>

int main(){
    int dp[1001] = {0};
    int N;
    dp[1] = 1;
    dp[2] = 2;
    std::cin>>N;

    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    std::cout<<dp[N];

    return 0;
}