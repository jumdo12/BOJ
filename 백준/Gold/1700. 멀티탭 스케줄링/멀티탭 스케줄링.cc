#include <iostream>
#include <vector>
#include <set>


using namespace std;

int N, M;
vector<int> v;
set<int> pluged;

int sum;

int main() {
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    int ans = 0;
    for(int i=0; i<M; i++) {
        int curr = v[i];

        // contains
        if(pluged.find(curr) != pluged.end()) {
            continue;
        }

        if(pluged.size() < N) {
            pluged.insert(curr);
            continue;
        }

        int toUnplug = -1;
        int maxNext= -1;
        for(auto s : pluged) {
            int next = -1;
            for(int j = i + 1; j < M; j++) {
                if(v[j] == s) {
                    next = j;

                    maxNext = max(maxNext, next);
                    break;
                }        
            }

            if(next == -1) {
                toUnplug = s;
                break;
            }
        }

        if(toUnplug == -1) {
            pluged.erase(v[maxNext]);
        } else {
            pluged.erase(toUnplug);
        }

        ans++;
        pluged.insert(curr);
    }

    cout << ans;
}
