#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;

    set<int> s;
    vector<int> v;
    vector<int> dist;

    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;

        if(s.find(tmp) == s.end()) {
            s.insert(tmp);
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end());

    int curr = v[0];
    for(int i=1; i<v.size(); i++) {
        dist.push_back(abs(v[i]-curr));

        curr = v[i];
    }

    sort(dist.begin(), dist.end());

    int sum = 0;

    if (M >= v.size())
    {
        cout << 0;
        return 0;
    }
    for(int i=0; i<dist.size() - (M - 1); i++) {
        sum += dist[i];
    }

    cout << sum ;
    
    return 0;
}
