#include <iostream>

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int N,ans;
    int dp[1001][3] = {0,};

    std::cin>>N;
    for(int i=1; i<=N; i++){
        std::cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
    }
    ans = min(dp[N][0],min(dp[N][1],dp[N][2]));
    std::cout<<ans;
    return 0;
}