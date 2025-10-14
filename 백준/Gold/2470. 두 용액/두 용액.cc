#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> v;

int main() {
    cin >> N;
    
    for(int i=0; i < N; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = N - 1;
    int ansLeft, ansRight, minSum;
    
    ansLeft = left;
    ansRight = right;
    minSum = v[left] + v[right];

    while(left < right) {
        int sum = v[left] + v[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            ansLeft = left;
            ansRight = right;
        }

        if(sum < 0) {
            left++;
        } else if(sum > 0) {
            right--;
        } else {
            break;
        }
    }

    cout << v[ansLeft] << " " << v[ansRight];
}
