#include <stdio.h>

int main(){
    int dp[100];
    int t; scanf("%d" , &t);
    dp[0] = 1;
    for(int i=1; i<=t; i++){
        dp[i] = dp[i-1] * i;
    }
    printf("%d" , dp[t]);
}