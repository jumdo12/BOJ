#include <iostream>

int main(){
    int dp[1000];
    dp[1] = 1;
    dp[2] = 3;
    int N;
    std::cin>>N;

    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1] + 2 * dp[i-2])%10007;
    }

    std::cout<<dp[N];
    return 0;
}