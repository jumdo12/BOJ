#include <iostream>

using namespace std;

int main() {
	int N, count, flag ,len; cin >> N;
	int alpha[26];

	string str;

	count = N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		len = str.length();
		flag = 0;


		for (int j = 0; j < 26; j++) {
			alpha[j] = 0;
 		}

		alpha[str[0] - 'a'] = 1;

		for (int j = 1; j < len; j++) {
			if (str[j] != str[j - 1]) {
				if (alpha[str[j] - 'a']) {
					count--;
					break;
				}
				else {
					alpha[str[j] - 'a'] = 1;
				}
			}
		}
	}

	cout << count;

	return 0;
}