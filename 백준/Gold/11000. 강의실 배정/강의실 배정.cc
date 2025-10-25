#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;

        pair<int,int> p = {start, end};

        v.push_back(p);
    }

    sort(v.begin(), v.end());

    for(auto p : v) {
        if(pq.empty()) {
            pq.push(p.second);
            continue;
        }

        int recently = pq.top();

        if(p.first < recently) {
            pq.push(p.second);
        }
        else {
            pq.pop();
            pq.push(p.second);
        }
    }

    cout << pq.size();
}
