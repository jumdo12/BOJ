#include <iostream>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int N;
int dp[1000001][2] = {0,};

void func(int target, int curr) {
    if(target > N) {
        return;
    }

    auto prevIdx = dp[target][0];
    if(prevIdx == 0){
        dp[target][0] = curr;
        dp[target][1] = dp[curr][1] + 1;

        return;
    }

    if(dp[target][1] > dp[curr][1]) {
        dp[target][0] = curr;
        dp[target][1] = dp[curr][1] + 1;
    }

    return;
}

int main() {
    cin >> N;

    for(auto i = 1; i <= N; i++) {
        func(i * 2, i);
        func(i * 3, i);
        func(i + 1, i);
    }

    cout << dp[N][1] << endl;

    cout << N << " ";
    int prevIdx = dp[N][0];
    while(prevIdx != 0) {
        cout << prevIdx << " ";
        prevIdx = dp[prevIdx][0];
    }
    
    return 0;
}
