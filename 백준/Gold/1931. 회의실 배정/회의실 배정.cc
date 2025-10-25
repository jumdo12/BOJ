#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

int N;
vector<pair<int,int>> v;
stack<pair<int,int>> ans;

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int start, end;

        cin >> start >> end;

        v.push_back({start, end});
    }

    sort(
        v.begin(),
        v.end(),
        [](pair<int,int> a, pair<int,int> b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    );

    for(auto p : v) {
        if(ans.empty()) {
            ans.push(p);
            continue;
        }

        auto curr = ans.top();

        if(p.first < curr.second) {
            continue;
        }

        ans.push(p);
    }

    cout << ans.size();
}