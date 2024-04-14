#include <iostream>

int main(){
    int dp[31] = {0};
    int N;

    std::cin>>N;

    dp[2] = 3;        

    for(int i = 4; i <= N; i+=2){
        dp[i] = dp[i-2] * dp[2];

        for(int j = i - 4; j > 0; j-=2){
            dp[i] += (2 * dp[j]);
        }
        dp[i] += 2;
    }

    std::cout<<dp[N];

    return 0;
}