#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int N;
int length;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;

        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    int end = v[0].second;
    int sum = abs(v[0].second - v[0].first);

    for(int i = 1; i < N; i++) {
        auto curr = v[i];
        int currStart = curr.first;
        int currEnd = curr.second;

        if(currStart <= end && currEnd > end) {
            sum += abs(currEnd - end);
            
            end = currEnd;
        }

        if(currStart > end) {
            sum += abs(currEnd - currStart);
            end = currEnd;
        }
    }

    cout << sum;
}
