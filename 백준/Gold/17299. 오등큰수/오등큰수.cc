#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int arr[1000001] = {0};

    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N, temp;
    std::cin >> N;

    std::vector<int> v(N);
    std::vector<int> s;
    std::vector<int> ans;

    for (int i = 0; i < N; i++)
    {
        std::cin>>temp;
        v[i] = temp;
        arr[temp]++;
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push_back(i);
            ans.push_back(-1);
        }
        else
        {
            while (!s.empty() && arr[v[s.back()]] <= arr[v[i]])
            {
                s.pop_back();
            }
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(v[s.back()]);
            }
            s.push_back(i);
        }
    }

    while (!ans.empty())
    {
        std::cout << ans.back() << " ";
        ans.pop_back();
    }

    return 0;
}