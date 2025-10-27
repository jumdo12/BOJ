#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;

int toDate(int month, int day) {
    return month * 100 + day;
}

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int startMonth, startDay, endMonth, endDay;
        cin >> startMonth >> startDay >> endMonth >> endDay;

        v.push_back({toDate(startMonth, startDay), toDate(endMonth, endDay)});
    }

    sort(v.begin(), v.end());

    int currEnd = toDate(3,1);
    int currEndIdx = -1;
    int count = 0;

    while(currEnd <= toDate(11,30)) {
        int maxEnd = currEnd;

        for(int nextIdx = 0; nextIdx < N; nextIdx++) {
            if(v[nextIdx].first <= currEnd) {
                maxEnd = max(maxEnd, v[nextIdx].second);
            }
            else {
                break;
            }
        }

        if(maxEnd == currEnd) {
            cout << 0 << endl;
            return 0;
        }

        currEnd = maxEnd;
        count++;
    }

    cout << count;
    return 0;

}