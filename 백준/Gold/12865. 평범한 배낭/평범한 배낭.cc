#include <iostream>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int N,K;

    int dp[101][100001] = {0};
    int V[101] = {0};
    int W[101] = {0};

    std::cin>>N>>K;

    for(int i=1; i<=N; i++){
        std::cin>>W[i]>>V[i];
    }

    for(int j = 1; j<=K; j++){
        for(int i = 1; i<=N; i++){
            if(W[i] > j)    dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j] , V[i] + dp[i-1][j-W[i]]);
            }
        }
    }

    std::cout<<dp[N][K];

    return 0;
}