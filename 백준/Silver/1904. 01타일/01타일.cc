#include <iostream>

int DP[1000001];

int dp(int N){
    if(N == 1)  return 1;
    if(N == 2)  return 2;

    if(DP[N])   return DP[N];
    else
        DP[N] = (dp(N - 2) + dp(N - 1)) % 15746;
    return DP[N];
}

int main(){
    int N;
    std::cin>>N;
    std::cout << dp(N);
    return 0;
}