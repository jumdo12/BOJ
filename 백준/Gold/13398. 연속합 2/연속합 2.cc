#include <iostream>

int max(int a , int b){
    return a > b ? a : b;
}

int main(){
    int N,ans;
    int arr[100000] = {0};
    int dp[100000][2] = {0};

    std::cin>>N;
    
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }

    dp[0][0] = dp[0][1] = arr[0];
    ans = max(dp[0][0] , dp[0][1]);

    for(int i = 1; i < N; i++){
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }

    std::cout<<ans;

    return 0;
}