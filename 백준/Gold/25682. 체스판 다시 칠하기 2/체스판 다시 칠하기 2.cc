#include <iostream>

int Min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int N,M,K,temp;
    char board[2001][2001]={0};
    int sum[2001][2001] = {0};
    int min, ans = 9999999;
    std::cin>>N>>M>>K;

    for(int i=1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            std::cin>>board[i][j];
            sum[i][j] = ((i + j) % 2 == 0 ? 'W' : 'B') != board[i][j];
            sum[i][j] += (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
        }
    }

    for (int i = K; i <= N; i++)
    {
        for (int j = K; j <= M; j++)
        {
            int temp = sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K];
            int min = Min(K * K - temp, temp);
            ans = Min(ans, min);
        }
    }

    std::cout<<ans;

    return 0;
}