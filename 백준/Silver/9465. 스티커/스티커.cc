#include <iostream>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int T,N,temp,ans = 0;
    int dp[100001][2] = {0};

    std::cin>>T;
    for(int i=0; i<T; i++){
        ans = 0;
        std::cin>>N;
        for(int j=0; j<2; j++){
            for(int k =1; k<=N; k++){
                std::cin>>dp[k][j];
            }
        }

        ans = max(dp[1][0],dp[1][1]);

        for(int j=2; j<=N; j++){
            dp[j][0] += max(max(dp[j-1][1],dp[j-2][1]),dp[j-2][0]);
            dp[j][1] += max(max(dp[j-1][0],dp[j-2][0]),dp[j-2][1]);    
            
            ans = max(dp[j][0],dp[j][1]);
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}