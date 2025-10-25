#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;

        pq.push(tmp);
    }

    long long total = 0;
    while(pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        long long sum = (first + second);

        total += sum;
        
        pq.push(sum);
    }

    cout << total;
}