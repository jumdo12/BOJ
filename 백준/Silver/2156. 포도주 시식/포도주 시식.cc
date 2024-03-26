#include <iostream>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int N;
    int dp[10001] = {0};
    int arr[10001] = {0};
    std::cin>>N;
    for(int i=1; i<=N; i++){
        std::cin>>arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i<=N; i++){
        dp[i] = max(max(dp[i-3] + arr[i-1],dp[i-2]) + arr[i] , dp[i-1]);
    }

    std::cout<<dp[N];

    return 0;
}