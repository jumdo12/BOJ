#include <iostream>

using namespace std;

int main() {
	int N, cnt = 1, sum = 1; cin >> N;

	while (sum < N) {
		sum += 6 * cnt;
		cnt++;
	}

	cout << cnt;

	return 0;
}