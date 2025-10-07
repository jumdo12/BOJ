#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    int absN = abs(n);

    v.push_back(0);
    v.push_back(1);

    for(int i=2; i <= absN; i++) {
        v.push_back((v[i - 2] + v[i - 1]) % 1000000000);
    }

    if(n == 0) {
        cout << 0 << endl;
        cout << 0;
    }
    else if(n > 0) {
        cout << 1 << endl;
        cout << v[absN];
    } else {
        if (n % 2 == 0){
            cout << -1 << endl;
            cout << v[absN];
        } else {
            cout << 1 << endl;
            cout << v[absN];
        }
    }

    return 0;
}