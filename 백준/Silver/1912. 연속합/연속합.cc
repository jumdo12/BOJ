#include <iostream>
#include <stdlib.h>

int max(int a ,int b){
    return a > b ? a : b;
}

int main(){
    int N,sum = 0,num;
    int *dp;
    std::cin>>N;

    dp = new int[N];

    std::cin>>num;
    sum += num;
    dp[0] = num;
    if(sum < 0) sum = 0;

    for(int i=1; i<N; i++){
        std::cin>>num;
        sum += num;
        dp[i] = max(dp[i-1],sum);
        if(sum < 0) sum = 0;
    }

    std::cout<<dp[N-1];
    free(dp);

    return 0;
}