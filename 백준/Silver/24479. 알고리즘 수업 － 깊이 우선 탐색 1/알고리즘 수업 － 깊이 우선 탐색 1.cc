#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> graph[1000001];
int visited[100001] = {0};
int cnt = 1;

void DFS(int S){
    if(!visited[S]){
        visited[S] = cnt++;
        for(int i=0; i<graph[S].size(); i++){
            DFS(graph[S][i]);
        }
    }
    return;
}

int main(){
    int src,dest,V,E,S;

    std::cin>>V>>E>>S;
    
    for(int i=0; i<E; i++){
        std::cin>>src>>dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    for(int i = 1; i<= V; i++){
        std::sort(graph[i].begin(),graph[i].end());
    }

    DFS(S);

    for(int i=1; i<=V; i++){
        std::cout<<visited[i]<<'\n';
    }

    return 0;
}