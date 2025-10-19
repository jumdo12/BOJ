#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N,M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    map<int, vector<int>> g;
    vector<int> inDegree(N+1, 0);
    queue<int> q;

    for(int i=0; i<M; i++) {
        int left, right;
        cin >> left >> right;

        g[left].push_back(right);
        inDegree[right]++;
    }

    for(int i=1; i <= N; i++) {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for(auto next : g[curr]) {
            inDegree[next]--;

            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
}
