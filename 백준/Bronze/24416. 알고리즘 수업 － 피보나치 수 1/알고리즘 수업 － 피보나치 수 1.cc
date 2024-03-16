#include <iostream>

int A=0,B;

int fibo(int N){
    if(N==1||N==2){
        A++;
        return 1;
    }
    else    return fibo(N-1)+fibo(N-2);
}

void fibo_dp(int N){
    B = N-2;
}

int main(){
    int T;
    std::cin>>T;
    fibo(T);
    fibo_dp(T);
    std::cout<<A<<" "<<B;
    return 0;
}