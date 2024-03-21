#include <iostream>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int arr[301] = {0};
    int dp[301] = {0};

    int N;
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }

    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];
    dp[2] = dp[0] + arr[2];

    for(int i = 2; i<N; i++){
        dp[i] = max(dp[i-3] + arr[i-1], dp[i-2]) + arr[i] ;
    }

    std::cout<<dp[N-1];

    return 0;
}