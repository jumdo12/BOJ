#include <iostream>

using namespace std;

int main() {
	int arr[5001] = { 0 };
	int N; cin >> N;
	arr[3] = 1; arr[5] = 1;

	for (int i = 6; i < 5001; i++) {
		if (arr[i - 3] && arr[i - 5]) {
			arr[i] = min(arr[i - 3], arr[i - 5]) + 1;
		}
		else if (arr[i - 3]) {
			arr[i] = arr[i - 3]+1;
		}
		else if (arr[i - 5]) {
			arr[i] = arr[i - 5]+1;
		}
	}

	if (arr[N]) {
		cout << arr[N];
	}
	else {
		cout << -1;
	}

	return 0;
}