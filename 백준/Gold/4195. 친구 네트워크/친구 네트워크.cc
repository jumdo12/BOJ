#include <iostream>
#include <map>
#include <string>

using namespace std;

int N,M;
map<string, int> m;
int parent[1000001] = {0};
int friendSize[1000001] = {0};
int idx = 1;

int getName(string name) {
    if(m.find(name) == m.end()) {
        m[name] = idx++;
    }

    return m[name];
}

int findParent(int curr)
{
    if (parent[curr] == curr){
        return curr;
    }

    return parent[curr] = findParent(parent[curr]);
}

int unionParent(int left, int right) {
    int leftParent = findParent(left);
    int rightParent = findParent(right);

    if(leftParent != rightParent) {
        parent[leftParent] = rightParent;
        friendSize[rightParent] += friendSize[leftParent];
    }

    return friendSize[rightParent];
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> M;

        for(int i=0; i<=200000; i++) {
            parent[i] = i;
            friendSize[i] = 1;
        }

        m.clear();
        idx = 1;

        for(int j=0; j<M; j++) {
            string left, right;
            cin >> left >> right;

            int leftParent = findParent(getName(left));
            int rightParent = findParent(getName(right));

            int unionedSize = unionParent(leftParent, rightParent);
            cout << unionedSize << '\n';
        }
    }

    return 0;
}