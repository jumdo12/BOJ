#include <iostream>

using namespace std;

int N,M;

int parent[201] = {0};

int findParent(int curr) {
    if(parent[curr] == curr) {
        return curr;
    }

    return parent[curr] = findParent(parent[curr]);
}

void unionParent(int left, int right) {
    int leftParent = findParent(left);
    int rightParent= findParent(right);

    if(leftParent != rightParent) {
        parent[leftParent] = parent[rightParent];
    }
}

int main() {
    cin >> N;
    cin >> M;

    for(int i=0; i<=N; i++) {
        parent[i] = i;
    }

    for(int i=1; i<=N; i++) {
        for(int j = 1; j<=N; j++) {
            int tmp;

            cin >> tmp;

            if(tmp == 0) {
                continue;
            }

            int currParent = findParent(i);
            int otherParent = findParent(j);

            if(currParent != otherParent) {
                unionParent(currParent, otherParent);
            }
        }
    }

    int tmp;
    cin >> tmp;

    int currParent = findParent(tmp);
    for(int i=1; i<M; i++) {
        cin >> tmp;

        int nextParent = findParent(tmp);

        if(currParent != nextParent) {
            cout << "NO";
            return 0;
        }

        currParent = nextParent;
    }

    cout << "YES";
    return 0;
}
