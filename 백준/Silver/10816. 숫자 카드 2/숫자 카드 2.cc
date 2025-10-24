#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    map<int,int> m;
    
    cin >> N;

    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;

        m[tmp]++;
    }

    cin >> M;

    for(int i=0; i<M; i++) {
        int tmp;
        cin >> tmp;

        cout << m[tmp] << " ";
    }
}