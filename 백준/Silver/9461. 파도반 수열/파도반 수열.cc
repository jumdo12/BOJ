#include <iostream>

int main(){
    int N,num;
    long long DP[101];

    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = DP[5] = 2;

    for(int i = 6; i<101; i++){
        DP[i] = DP[i-1] + DP[i-5];
    }

    std::cin>>N;
    while(N--){
        std::cin>>num;
        std::cout<<DP[num]<<'\n';
    }

    return 0;
}