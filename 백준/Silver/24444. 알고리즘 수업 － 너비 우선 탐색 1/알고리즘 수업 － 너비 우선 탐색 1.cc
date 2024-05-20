#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> graph[1000001];
int visited[100001] = {0};
int cnt = 1;

void BFS(int S)
{
    std::queue<int> q;

    q.push(S);

    while(!q.empty()){
        S = q.front();
        q.pop();

        if (!visited[S]){
            visited[S] = cnt++;
            for (int i = 0; i < graph[S].size(); i++){
                q.push(graph[S][i]);
            }
        }
    }

    return;
}

int main()
{
    int src, dest, V, E, S;

    std::cin >> V >> E >> S;

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

    BFS(S);

    for (int i = 1; i <= V; i++)
    {
        std::cout << visited[i] << '\n';
    }

    return 0;
}