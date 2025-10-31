#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int N;
vector<pair<pair<int,int>,int>> v; 
map<int,int> m;

int main() {
    int max = 0;
    cin >> N;

    for(int i=0; i<N; i++) {
        int country, num, point;
        cin >> country >> num >> point;

        v.push_back({{country, num}, point});
    }

    int count = 0;
    while(1) {
        if(count == 3){
            break;
        }

        int maxIdx = -1;
        int max = 0;
        for(int i=0; i<N; i++) {
            if(max < v[i].second && m[v[i].first.first] < 2) {
                maxIdx = i;
                max = v[i].second;
            }
        }

        count++;
        cout << v[maxIdx].first.first << " " << v[maxIdx].first.second << endl;
        v[maxIdx].second = -1;
        m[v[maxIdx].first.first]++;
    }

    return 0;
}