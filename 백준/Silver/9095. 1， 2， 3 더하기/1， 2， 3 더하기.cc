#include <iostream>

int main(){
    int N;
    int dp[12];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=4; i<=11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    std::cin>>N;
    while(N--){
        int num;
        std::cin>>num;
        std::cout<<dp[num]<<'\n';
    }

    return 0;
}