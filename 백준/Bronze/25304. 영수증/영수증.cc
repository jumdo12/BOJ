#include <iostream>
int main(){
    int X,N,a,b,sum=0;
    std::cin>>X >>N;
    for(int i=0; i<N; i++){
        std::cin>>a>>b;
        sum += a*b;
    }
    if(sum == X)    std::cout<<"Yes";
    else    std::cout<<"No";  
    return 0;
}