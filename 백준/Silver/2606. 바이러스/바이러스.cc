#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> graph[101];
int visited[101] = {0};

void BFS(int S)
{
    std::queue<int> q;

    q.push(S);

    while (!q.empty())
    {
        S = q.front();
        q.pop();

        if (!visited[S])
        {
            visited[S] = 1;
            for (int i = 0; i < graph[S].size(); i++)
            {
                q.push(graph[S][i]);
            }
        }
    }

    return;
}

int main()
{
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int src, dest, V, E;
    int cnt = 0;

    std::cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        std::cin >> src >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    for (int i = 1; i <= V; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }

    BFS(1);

    for (int i = 1; i <= V; i++)
    {
        if(visited[i])  cnt++;
    }

    std::cout<<cnt-1;

    return 0;
}