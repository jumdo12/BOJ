#include <iostream>

int Combination(int N, int K){
    int arr[11],ans;
    arr[0] = arr[1] = 1;
    for(int i=2; i<=N; i++){
        arr[i] = arr[i-1] * i;
    }
    ans = arr[N] / arr[K];
    ans /= arr[N-K];
    return ans;
}

int main(){
    int N,K;
    std::cin>>N>>K;

    std::cout<<Combination(N,K);

    return 0;
}