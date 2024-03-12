#include <iostream>

int checked[9] = {0};

void back_tracking(int *arr, int curr, int N, int M)
{
    if (curr == M)
    {
        for (int i = 0; i < M; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if(curr != 0 && arr[curr-1] > i)    continue;
            checked[i] = 1;
            arr[curr] = i;
            back_tracking(arr, curr + 1, N, M);
            checked[i] = 0;
            arr[curr] = 0;
        }
    }
}

int main()
{
    int arr[9] = {0};
    int N, M;
    std::cin >> N >> M;

    back_tracking(arr, 0, N, M);

    return 0;
}