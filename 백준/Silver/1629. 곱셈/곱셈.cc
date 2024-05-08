#include <iostream>

long long recv(long long a, long long b, long long c)
{
    if (b == 0) return 1;
    if (b == 1) return a % c;

    long long temp = recv(a, b / 2, c) % c;

    if (b % 2 == 0)
    {
        return (temp * temp) % c;
    }
    else
    {
        return ((temp * temp) % c * (a % c)) % c;
    }
}

int main()
{
    long long a, b, c;

    std::cin >> a >> b >> c;
    std::cout << recv(a, b, c);
    return 0;
}