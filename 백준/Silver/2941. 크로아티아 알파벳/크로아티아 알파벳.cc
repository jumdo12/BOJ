#include <iostream>

using namespace std;

int main() {
	string str; cin >> str;
	int len = str.length() , sum = len;

	for (int i = len; i>= 1; i--) {
		if (str[i] == '=') {
			sum--;
			if (str[i - 2] == 'd' && str[i - 1] == 'z' && i >= 2) {
				sum--;
			}
		}
		else if (str[i] == '-') {
			sum--;
		}
		else if (str[i] == 'j' && (str[i - 1] == 'l' || str[i - 1] == 'n')) {
			sum--;
		}
	}

	cout << sum;

	return 0;
}