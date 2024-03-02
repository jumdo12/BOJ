#include <iostream>

bool is_prime(long long num){
    if (num <= 1)
        return false;

    if (num == 2 || num == 3)
        return true;

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (long long i = 5; i * i <= num; ++i)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
     
    int N;
    long long n;
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>n;
        while(!is_prime(n)){
            n++;
        }
        std::cout<<n<<'\n';
    }
    return 0;
}