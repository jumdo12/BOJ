#include <iostream>

using namespace std;

int main()
{
	int idx, n, max = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		if (n > max)
		{
			idx = i;
			max = n;
		}
	}

	cout << max << endl;
	cout << idx+1 << endl;

	return 0;
}