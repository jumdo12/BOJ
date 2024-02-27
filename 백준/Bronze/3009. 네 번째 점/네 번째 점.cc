#include <iostream>

int main(){
    int X[1001]={0},Y[1001]={0};
    int A,B;
    for(int i=0; i<3; i++){
        std::cin>>A>>B;
        X[A]++;
        Y[B]++;
    }

    for(int i=0; i<=1001; i++){
        if(X[i] == 1)   A = i;
        if(Y[i] == 1)   B = i;
    }

    std::cout <<A <<" " <<B;

    return 0;
}