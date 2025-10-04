#include <iostream>
#include <algorithm>

using namespace std;

int profit[1500002] = {0};
int times[1500002] = {0}; 
int dp[1500002] = {0};

int N;

int main() {
    cin >> N;

    for(int i=1; i<=N; i++) {
        cin >> times[i] >> profit[i];
    }

    for(int i=1; i<=N; i++) {
        dp[i] = max(dp[i], dp[i-1]);

        int profitDay = times[i] + i;

        if(profitDay > N + 1) {
            continue;
        }

        dp[profitDay] = max(dp[profitDay], dp[i] + profit[i]);
    }

    cout << max(dp[N], dp[N+1]);
}