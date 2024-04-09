#include <iostream>

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int N;
    int dp[100001] = {0};

    std::cin>>N;

    for(int i=1; i<=N; i++){
        dp[i] = i;
    }

    for(int i = 2; i<=N; i++){
        for(int j=1; j*j <= i; j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }

    std::cout<<dp[N];

    return 0;
}