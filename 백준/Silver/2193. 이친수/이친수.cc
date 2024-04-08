#include <iostream>

int main(){
    long long dp[91][3] = {0};
    dp[1][1] = dp[2][0] = 1;
    dp[1][0] = dp[2][1] = 0;

    int N;
    std::cin>>N;

    for(int i = 3; i<= N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    std::cout<<dp[N][0] + dp[N][1];
}