#include <iostream>

using namespace std;

int main()
{
	int A, B, C , Max;
	
	cin >> A >> B >> C;

	if (B == A && B == C)
	{
		cout << 10000 + 1000 * B;
	}
	else if (A == B || A == C)
	{
		cout << 1000 + A * 100;
	}
	else if (B == C)
	{
		cout << 1000 + B * 100;
	}
	else
	{
		Max = (A > B) ? A : B;
		Max = (Max > C) ? Max : C;

		cout << Max * 100;
	}

	return 0;
}