#include <iostream>
#include <cmath>

using namespace std;

long long N;
int M;

long long ans = INT32_MAX;
int maxCount = 0;

int main() {
    cin >> N;
    cin >> M;

    long long left = 1;
    long long right = N*N;

    while(left <= right) {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for(long long i=1; i<=N; i++) {
            long long tmp = mid / i;

            if(tmp > N) {
                sum += N;
            }
            else {
                sum += tmp;
            }
        }

        if(sum < M) {
            left = mid + 1;
        } else {
            ans = min(ans, mid);

            right = mid - 1;
        }
    } 

    cout << ans;
}
