#include <iostream>

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int N,ans = 100012311;
    int dp[1001][3] = {0,};
    int arr[1001][3];
    int max = 12345678;

    std::cin>>N;
    
    for(int i=1; i<=N; i++){
        std::cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    
    for(int s = 0; s <= 2; s++){
        for(int j = 0; j<=2; j++){
            if(j == s){
                dp[1][s] = arr[1][s];
            }
            else{
                dp[1][j] = max;
            }
        }
        for(int i=2; i<=N; i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
        }
        for(int i=0; i<3; i++){
            if(i == s){
                continue;
            }
            ans = min(ans , dp[N][i]);
        }
    }
    
    std::cout<<ans;
    return 0;
}