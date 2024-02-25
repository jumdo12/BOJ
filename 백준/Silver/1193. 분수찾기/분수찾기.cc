#include <iostream>

using namespace std;

int main() {
	int X, sum = 0, tmp, idx; cin >> X;

	for (int i = 0; i <100001; i++) {
		if (X <= sum) {
			tmp = i;
			idx = X - (sum - i + 1);
			break;
		}
		sum += i;
	}

	if (tmp % 2 == 0) {
		cout << tmp - idx << "/" << idx;
	}
	else {
		cout << idx << "/" << tmp - idx;
	}

	return 0;
}