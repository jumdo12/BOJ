#include <iostream>

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    int N,M,left,right;
    int arr[100001] = {0};
    std::cin>>N>>M;

    for(int i=1; i<=N; i++){
        std::cin>>arr[i];
        arr[i] += arr[i-1];
    }

    for(int i=0; i<M; i++){
        std::cin>>left>>right;
        std::cout<<arr[right] - arr[left-1]<<'\n';
    }

    return 0;
}