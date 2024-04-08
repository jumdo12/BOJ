#include <iostream>
#include <vector>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int N,ans = 0;
    int arr[1001] = {0};
    int dp[1001] = {0};
    std::vector<int> v;

    std::cin>>N;
    for(int i=1; i<=N; i++){
        std::cin>>arr[i];
    }

    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(arr[i] > arr[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i =1; i<= N; i++){
        ans = max(ans,dp[i]);
    }

    std::cout << ans << '\n';
    int cnt = ans;

    for(int i = N; i>0; i--){
        if(dp[i] == cnt){
            v.push_back(arr[i]);
            cnt--;
        }
    }

    for(int i = v.size()-1; i >=0; i--){
        std::cout<<v[i]<<" ";
    }

    return 0;
}