#include <iostream>

#define c 1000000007

long long pow(long long a, long long b){
    long long ret = 1;
    
    while(b){
        if(b % 2) ret = (ret * a) % c;

        a = (a * a) % c;
        b /= 2; 
    }

    return ret;
}

int main(){
    long long n,r;

    long long a,b;
    a = b = 1;

    std::cin>>n>>r;

    for(int i = n; i >= n - r + 1; i--){
        a = (a * i) % c;
    }

    for(int i = 2; i <= r; i++){
        b = (b * i) % c;
    }

    std::cout<< (a * pow(b,c-2)) % c;


    return 0;
}