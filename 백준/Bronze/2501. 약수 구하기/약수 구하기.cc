#include <iostream>

int main(){
    int N,K,idx=1;
    int arr[10002];
    std::cin>>N>>K;

    for(int i=1;i<=N;i++){
        if(N%i == 0){
            arr[idx] =i;
            idx++;
        }
    }

    std::cout<<arr[K];

    return 0;
}