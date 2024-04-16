#include <iostream>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int N,K,ans;
    int arr[100001] = {0};
    std::cin>>N>>K;
    for(int i=1; i<=N; i++){
        std::cin>>arr[i];
        arr[i] += arr[i-1];
    }

    ans = arr[K];
    for(int i = K+1; i <= N; i++){
        ans = max(ans,arr[i] - arr[i - K]);
    }
    std::cout<<ans;
    return 0;
}