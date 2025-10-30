#include <iostream>

using namespace std;

int n,m;
int parent[500001] = {0};

int findParent(int x) {
    if(parent[x] == x) {
        return x;
    }

    return parent[x] = findParent(parent[x]);
}

void unionParent(int left, int right) {
    int leftParent = findParent(left);
    int rightParent = findParent(right);

    if(leftParent != rightParent) {
        parent[leftParent] = rightParent;
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int left, right;

        cin >> left >> right;

        int leftParent = findParent(left);
        int rightParent = findParent(right);

        if(leftParent != rightParent) {
            unionParent(leftParent, rightParent);
        }
        else {
            cout << i + 1;
            return 0;
        }
    }

    cout << 0;
    return 0;
}