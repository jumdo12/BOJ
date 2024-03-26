#include <iostream>

long long func(long long n, long long x){
    long long num = 0;
    for(long long i = x; i <= n; i *= x){
        num += (n / i);
    }
    return num;
}

long long min(long long a, long long b){
    return a > b ? b : a;
}

int main(){
    long long N,M,cnt5,cnt2;
    std::cin>>N>>M;

    cnt5 = func(N,5) - func(N-M,5) - func(M,5);
    cnt2 = func(N,2) - func(N-M,2) - func(M,2);

    std::cout<<min(cnt2,cnt5);

    return 0;
}