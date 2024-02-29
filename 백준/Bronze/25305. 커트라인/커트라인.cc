#include <iostream>
#define SWAP(x,y,z) ((z=x),(x=y),(y=z))
int main(){
    int N,K;
    std::cin>>N>>K;
    int* arr = new int[N];
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }

    for(int i=1; i<N;i++){
        int j,key;
        key = arr[i];
        for(j=i-1; j>=0 && arr[j] < key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

    std::cout<<arr[K-1];

    return 0;
}