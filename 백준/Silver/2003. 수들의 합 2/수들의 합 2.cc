#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int cnt;

vector<int> v;

int main() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int left, right, sum;
    left = right = sum = 0;

    for(;right < N; right++){
        sum += v[right];

        while(sum > M) {
            sum -= v[left];
            left++;
        }

        if(sum == M) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}