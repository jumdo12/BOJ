#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int maxLength = 0;
int sum = 0;
vector<int> pos;
vector<int> neg;

int main() {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        int tmp;

        cin >> tmp;

        if(tmp < 0) {
            neg.push_back(abs(tmp));
        }
        else{
            pos.push_back(tmp);
        }

        if(abs(tmp) > maxLength) {
            maxLength = abs(tmp);
        }
    }   

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    for(int i = neg.size() - 1; i >= 0; i -= M) {
        sum += (2 * neg[i]);
    }

    for(int i = pos.size() - 1; i >= 0; i -= M) {
        sum += (2 * pos[i]);
    }

    sum -= maxLength;

    cout << sum;
    return 0;
}