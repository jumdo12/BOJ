#include <iostream>

int rec(int dp[][201], int n, int k){
    if(n == 0)  return 1;
    else if(k == 1) return 1;
    else if(dp[n][k])   return dp[n][k] % 1000000000;
    else{
        for(int i = 0; i<=n; i++){
            dp[n][k] += rec(dp,i,k-1);
            dp[n][k] %= 1000000000;
        }
        return dp[n][k];
    }
}

int main(){
    int N,K;
    int dp[201][201]={0};

    std::cin>>N>>K;

    for(int i = 0; i<=N; i++){
        dp[i][1] = 1;
    }
    for(int i = 0; i<=K; i++){
        dp[0][i] = 1;
    }
    
    std::cout<<rec(dp,N,K);

    return 0;
}