#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    int ansLeft, ansRight;
    long long minSum = __LONG_LONG_MAX__;
    vector<int> v;

    cin >> N;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    for(int i=0; i<N-1; i++) {
        int left, right;

        left = i + 1;
        right = N-1;

        while(left <= right) {
            int mid = (left + right) / 2;
            long long sum = v[i] + v[mid];

            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                ansLeft = i;
                ansRight = mid;
            }

            if(sum < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    cout << v[ansLeft] << " " << v[ansRight];
}