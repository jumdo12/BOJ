#include <iostream>

using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;

	int A;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (X > A)
		{
			cout << A << " ";
		}
	}
	return 0;
}