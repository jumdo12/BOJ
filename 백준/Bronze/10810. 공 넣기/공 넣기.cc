#include <iostream>

int main(){
    int N,M,i,j,k;
    std::cin>>N>>M;
    int *arr = new int[N];
    for(int l=0; l<M; l++){
        std::cin >>i >>j>>k;
        for(int m = i-1; m <= j-1; m++){
            arr[m] = k;
        }
    }
    for(int i=0; i<N; i++){
        std::cout << arr[i] <<" ";
    }
    delete []arr;
    return 0;
}