#include <iostream>

int main(){
    int arr[10];
    int N,K,sum = 0;
    std::cin>>N>>K;
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }

    N--;
    while(N>=0){
        if(K >= arr[N]){
            sum += (K / arr[N]);
            K %= arr[N];
        }
        N--;
    }
    std::cout<<sum;
    return 0;
}