#include <iostream>

int main(){
    int N;
    long long dp[100001][4] = {0};
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    dp[2][1] = 0;
    dp[2][2] = 1;
    dp[2][3] = 0;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i < 100001; i++)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
    }

    std::cin >> N;
    while(N--){
        int num;
        std::cin>>num;
        std::cout << (dp[num][1] + dp[num][2] + dp[num][3]) % 1000000009 << '\n';
    }
    

    return 0;
}