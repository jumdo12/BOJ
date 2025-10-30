#include <iostream>

using namespace std;

int arr[1000001] = {0};
int N;
int M;

int find(int curr) {
    if(arr[curr] == curr) {
        return curr;
    }
    return arr[curr] = find(arr[curr]);
}

void uni(int left, int right) {
    int leftRoot = find(left);
    int rightRoot = find(right);

    if(leftRoot != rightRoot) {
        arr[leftRoot] = rightRoot;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i<= N; i++) {
        arr[i] = i;
    }
 
    for(int i=0; i<M; i++) {
        int cmd, left, right;
        cin >> cmd >> left >> right;

        if(cmd == 0) {
            uni(left, right);
        }
        else {
            int leftRoot = find(left);
            int rightRoot = find(right);

            if (leftRoot == rightRoot)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}