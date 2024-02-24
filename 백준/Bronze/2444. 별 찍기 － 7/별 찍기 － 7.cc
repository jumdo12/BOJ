#include <iostream>

int abs(int n){
    return (n > 0) ? n : -n;
}

int main(){
    int N;
    std::cin>>N;

    for(int i=0; i<2*N-1; i++){
        for(int j=0; j<abs(N-1-i); j++){
            std::cout<<" ";
        }
        for(int j=0; j < (2*N-1) - abs(2*(N-1-i)); j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    return 0;
}