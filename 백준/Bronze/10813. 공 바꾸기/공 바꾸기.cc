#include <iostream>
int main(){
    int *arr;
    int N,M,A,B;
    std::cin >> N >> M;
    arr = new int[N+1];
    for(int i=0; i<N+1; i++){
        arr[i] = i;
    }
    for(int i=0; i<M; i++){
        std::cin >> A >> B;
        int temp = arr[A];
        arr[A] = arr[B];
        arr[B] = temp;
    }
    for(int i=1; i<N+1; i++){
        std::cout<<arr[i] << " ";
    }
    return 0;
}