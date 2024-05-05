#include <iostream>

int main()
{
    int N;
    int dp0[41] , dp1[41] = {0};

    dp0[0] = dp1[1] = 1;
    dp0[1] = dp1[0] = 0;
    for(int i=2; i<=40; i++){
        dp1[i] = dp1[i-1] + dp1[i-2];
        dp0[i] = dp0[i-1] + dp0[i-2];
    }

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin >> temp;
        std::cout << dp0[temp] << " " << dp1[temp] << '\n';
    }
    return 0;
}