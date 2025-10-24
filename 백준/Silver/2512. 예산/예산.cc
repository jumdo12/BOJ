#include <iostream>
#include <vector>

using namespace std;

int N;
int limit;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int maxBudge = 0;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;

        if(maxBudge < tmp) {
            maxBudge = tmp;
        }

        v.push_back(tmp);
    }

    cin >> limit;

    int left = 1;
    int right = maxBudge;

    int ansMax = 0;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for(int i=0; i<N; i++) {
            int budget = v[i];

            if(budget > mid) {
                sum += mid;
            } else {
                sum += v[i];
            }
        }

        if(sum > limit) {
            right = mid - 1;
        }
        else {
            if(sum > ansMax) {
                ansMax = sum;
                ans = mid;
            }

            left = mid + 1;
        }
    }

    cout << ans;
}
