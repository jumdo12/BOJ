#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int t; cin >> t;
    cin >> str;
    int sum = 0;

    for (int i = 0; i < t; i++)
    {
        sum += str[i] - '0';
    }

    cout << sum;

    return 0;
}