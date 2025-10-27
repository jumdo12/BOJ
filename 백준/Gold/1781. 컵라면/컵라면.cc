#include <iostream>
#include <utility>
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
        int time, reward;
        cin >> time >> reward;

        v.push_back({time, reward});
    }

    sort(v.begin(), v.end());

    for(int i=0; i<N; i++) {
        int deadline = v[i].first;
        int reward = v[i].second;

        if(pq.size() < deadline) {
            pq.push(reward);
            continue;
        }

        if(reward > pq.top()) {
            pq.pop();
            pq.push(reward);
        }
    }

    int sum = 0;
    int size = pq.size();
    for(int i=0; i<size; i++) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum;

    return 0;
}