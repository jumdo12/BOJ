#include <iostream>

int main(){
    int arr[1001] = {0};
    int dp[1001] = {0};
    int max;

    int N;
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>arr[i];
        dp[i] = 1;
    }

    for(int i=0; i<N; i++){
        max = 0;
        int j;

        for(int j = 0; j<i; j++){
            if(arr[j] > arr[i]){
                max = (max > dp[j] ? max : dp[j]);
            }
        }

        dp[i] = max + 1;
    }

    max = 0;
    for(int i=0; i<N; i++){
        max = (dp[i] > max ? dp[i] : max);
    }

    std::cout<<max;

    return 0;
}