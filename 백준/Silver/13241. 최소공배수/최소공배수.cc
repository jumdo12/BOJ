#include <iostream>

long long gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b,a%b);
}

int main(){
    long long A,B;
    std::cin>>A>>B;
    std::cout<<A*B/gcd(A,B);
    return 0;
}