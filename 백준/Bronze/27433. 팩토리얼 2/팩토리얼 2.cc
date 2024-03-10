#include <iostream>

long long fact(int N){
    if(N==0 || N == 1)  return 1;
    else    return N * fact(N-1);
}

int main(){
    int N;
    std::cin>>N;

    std::cout<<fact(N);

    return 0;
}