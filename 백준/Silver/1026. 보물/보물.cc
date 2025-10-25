#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> a;
vector<int> b;

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;

        a.push_back(tmp);
    }

    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](int a,int b){
        return a > b;
    });

    int sum = 0;

    for(int i=0; i<N; i++) {
        sum += a[i] * b[i];
    }

    cout << sum;
}
