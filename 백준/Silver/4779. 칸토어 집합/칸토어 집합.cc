#include <iostream>

int pow(int x, int n){
    if(n==0)    return 1;
    if(n%2 == 0)    return pow(x*x,n/2);
    else    return x * pow(x*x,(n-1)/2);
}

void cantor(int N){
    if(N==0)    std::cout<<"-";
    else{
        cantor(N-1);
        for(int i=0; i<pow(3,N-1); i++){
            std::cout<<" ";
        }
        cantor(N-1);
    }
}

int main(){
    int t;
    while(std::cin>>t){
        cantor(t);
        std::cout<<'\n';
    }
    return 0;
}