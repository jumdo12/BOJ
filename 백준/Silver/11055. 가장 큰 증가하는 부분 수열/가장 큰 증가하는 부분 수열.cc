#include <iostream>
#include <vector>

int main(){
    int N,temp,max = 0;
    int arr[1001] = {0};
    int dp[1001] = {0};
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }

    for(int i = 0; i < N; i++){
        max = 0;
        int j;
        for(j = 0; j<i; j++){
            if(arr[i] > arr[j]){
                if(max < dp[j]) max = dp[j];
            }
        }
        dp[i] = max + arr[i];
    }

    max = 0;

    for(int i=0; i<N; i++){
        max = max > dp[i] ? max : dp[i];
    }

    std::cout << max;

    return 0;
}