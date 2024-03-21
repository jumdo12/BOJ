#include <iostream>

int arr[3000004] = {0};
int dp[300004] = {0};

int min(int a ,int b){
    return a > b ? b : a;
}

int main(){
    int N;
    std::cin>>N;

    for(int i = 1; i<= N; i++){
        dp[3*i] = dp[3*i] ? min(dp[3*i],dp[i] + 1) : dp[i] + 1;
        dp[2 * i] = dp[2 * i] ? min(dp[2 * i], dp[i] + 1) : dp[i] + 1;
        dp[i+1] = dp[i+1] ? min(dp[i+1], dp[i] + 1) : dp[i] + 1;
    }
    std::cout<<dp[N];
    return 0;
}