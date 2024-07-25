#include <iostream>
#include <map>
#include <vector>

class Graph
{
public:
    std::map<int, std::vector<int>> g;
    int N;

    void push(int s, int e)
    {
        g[s].push_back(e);
        g[e].push_back(s);
    }

    void setVertex(int N)
    {
        this->N = N;
    }
};

int flag = 0;
std::map<int, int> visited;

void BinaryGraph(Graph &g, int v, int color)
{
    visited[v] = color;

    for (int neighbor : g.g[v])
    {
        if (visited[neighbor] == 0)
        {
            BinaryGraph(g, neighbor, -color);
        }
        else if (visited[neighbor] == color)
        {
            flag = 1;
            return;
        }
        else if (flag)
            return;
    }
}

int main()
{
    int T, V, E, s, e;
    std::cin >> T;
    while (T--)
    {
        std::cin >> V >> E;
        Graph g;
        flag = 0;
        visited.clear();

        for (int i = 0; i < E; i++)
        {
            std::cin >> s >> e;
            g.push(s, e);
        }

        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
            {
                BinaryGraph(g, i, 1);
            }
        }

        if (flag == 0)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
    return 0;
}
