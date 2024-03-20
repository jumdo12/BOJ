#include <iostream>

int dp[500][500];

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int N,temp;
    std::cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            std::cin>>temp;
            dp[i][j] = temp;
        }
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                dp[i][j] += dp[i-1][j];
            }
            else if(j == i){
                dp[i][j] += dp[i-1][j-1];
            }
            else{
                dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }

    int max = dp[N-1][0];
    for(int i = 1; i < N; i++){
        if(max < dp[N-1][i]){
            max = dp[N-1][i];
        }
    }

    std::cout<<max;

    return 0;
}