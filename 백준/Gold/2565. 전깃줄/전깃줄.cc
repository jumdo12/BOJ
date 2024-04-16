#include <iostream>
#include <algorithm>

typedef struct{
    int left;
    int right;
}Lines;

bool comp(Lines A, Lines B){
    return A.left < B.left;
}

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int dp[101] = {0};
    Lines lines[101];
    int N,ans;

    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>lines[i].left>>lines[i].right;
    }

    std::sort(lines,lines+N,comp);

    dp[0] = 1;
    ans = dp[0];

    for(int i = 1; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j< i; j++){
            if(lines[j].right < lines[i].right){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        ans = max(ans,dp[i]);
    }

    std::cout<<N-ans;

    return 0;
}