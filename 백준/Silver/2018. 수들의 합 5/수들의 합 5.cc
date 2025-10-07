#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    long long sum;
    int cnt, left, right;
    sum = left = right = cnt = 0;

    cin >> N;

    for(; right < N; right++) {
        sum += (right + 1);

        while(left < right && sum > N) {
            sum -= (left + 1);
            left++;
        }

        if(sum == N) {
            sum -= (left + 1);
            left++;
            cnt++;
        } 
    }

    cout << cnt;

    return 0;
}