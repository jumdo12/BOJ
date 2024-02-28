#include <iostream>

int func(int N){
    int temp , Sum;
    temp = Sum = N;
    while(temp){
        Sum += temp % 10;
        temp /= 10;
    }
    return Sum;
}

int main(){
    int N;
    int arr[2500000]={0};
    std::cin>>N;
    for(int i=1; i<1200000;i++){
        if(arr[func(i)]==0){
            arr[func(i)] = i;
        }
    }
    std::cout<< arr[N];
    return 0;
}