#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map <int, int> m;
vector<int> v;
int N, d, k, c, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d >> k >> c;
    ans = 0;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int left, right;
    for(int i=0; i<k; i++) {
        int tmp = v[i];

        m[tmp]++;
    }

    left = 0;
    right = left + k - 1;

    do {
        int cnt = m.size();

        if(m.find(c) == m.end()) {
            cnt++;
        }

        ans = max(ans, cnt);

        if(m[v[left]] == 1) {
            m.erase(v[left]);
        } else {
            m[v[left]]--;
        }

        left++;

        right = (right + 1) % N;
        m[v[right]]++;
    } while(left != N);

    cout << ans;

    return 0;
}