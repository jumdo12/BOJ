#include <iostream>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int ans;
    int cnt;
    int N;
    int dp[1000] = {0};
    int arr[1000] = {0};

    std::cin>>N;
    for(int i=1; i<=N; i++){
        std::cin>>arr[i];
    }

    ans = 0;
    for(int i=1; i<=N; i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans , dp[i]);
    }

    std::cout<<ans;

    return 0;
}