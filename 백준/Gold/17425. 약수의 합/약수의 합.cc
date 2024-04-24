#include <iostream>
#include <cmath>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T,N;
    long long sum[1000001] = {0};

    for(int i = 1; i <= 1000000; i++){
        sum[i] += i;
        for(int j = 2 * i; j <= 1000000; j+=i){
            sum[j] += i;
        }
        sum[i] += sum[i-1];
    }
    
    std::cin>>T;
    
    while(T--){
        std::cin>>N;
        std::cout<<sum[N]<<'\n';
    }
    return 0;
}