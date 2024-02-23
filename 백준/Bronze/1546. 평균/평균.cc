#include <iostream>

using namespace std;

int main()
{
	int N, max = 0;
	double arr[1001] = { 0 }, sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	}

	cout << sum / N;
}