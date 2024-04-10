#include <iostream>

int main(){
    int dp[1001][10] = {0};
    int N,ans=0;
    std::cin>>N;

    for(int i =1; i<=N; i++){
        for(int j = 0; j < 10; j++){
            if(i == 1){
                dp[i][j] = 1;
            }
            else{
                for(int k = 0; k <= j; k++){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= 10007;
                }
            }
        }
    }

    for(int i = 0; i<10; i++){
        ans += dp[N][i];
        ans %= 10007;
    }

    std::cout<<ans;

    return 0;
}