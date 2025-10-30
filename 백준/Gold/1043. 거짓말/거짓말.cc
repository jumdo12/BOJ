#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

int parent[52] = {0};
vector<int> events[52];

int findParent(int curr) {
    if (parent[curr] == curr) {
        return curr;
    }

    return parent[curr] = findParent(parent[curr]);
}

void unionParent(int left, int right) {
    int leftParent = findParent(left);
    int rightParent = findParent(right);

    if (leftParent != rightParent) {
        parent[leftParent] = parent[rightParent];
    }
}

int main() {
    cin >> N >> M;
    cin >> K;

    for(int i=0; i<=N; i++) {
        parent[i] = i;
    }

    int firstTruth = -1;
    if(K == 0) {
        cout << M;
        return 0;
    }

    for(int i=0; i<K; i++) {
        int tmp;
        cin >> tmp;

        if(i == 0) {
            firstTruth = tmp;
            continue;
        }

        unionParent(tmp, firstTruth);
    }

    for(int i=0; i < M; i++) {
        int cnt;
        cin >> cnt;

        int first;
        for(int j=0; j<cnt; j++) {
            int temp;
            cin >> temp;

            events[i].push_back(temp);

            if(j == 0) {
                first = temp;
                continue;
            }

            unionParent(temp, first);
        }
    }

    int ans = M;
    for(int i=0; i<M; i++) {
        for(int curr : events[i]) {
            int findLeft = findParent(curr);
            int findTruth = findParent(firstTruth);

            if(findLeft == findTruth) {
                ans--;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
