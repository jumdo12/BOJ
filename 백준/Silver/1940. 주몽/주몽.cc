#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int cnt;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int left, right;
    left = 0;
    right = N-1;

    while(left < right) {
        if(v[left] + v[right] == M) {
            cnt++;
            left++;
            right--;
            continue;
        }
        if(v[left] + v[right] < M) {
            left++;
            continue;
        }
        if(v[left] + v[right] > M) {
            right--;
            continue;
        }
    }

    cout << cnt;

    return 0;
}