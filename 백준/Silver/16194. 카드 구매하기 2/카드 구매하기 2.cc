#include <iostream>

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int arr[1001];
    int dp[1001];

    int N,temp;
    std::cin>>N;

    for(int i=1; i<=N; i++){
        std::cin>>arr[i];
    }

    dp[1] = arr[1];
    for(int i=2; i<=N; i++){
        dp[i] = arr[i];
        for(int j=1; j<i; j++){
            temp = i - j;
            dp[i] = min(dp[i],dp[j] + arr[temp]);
        }
    }

    std::cout<<dp[N];

    return 0;
}