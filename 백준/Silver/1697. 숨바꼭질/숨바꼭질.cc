#include <iostream>
#include <map>
#include <set>
#include <queue>

int visited[100001] = {0};
int dist[100001] = {0};

void BFS(int s, int e){
    int next;
    std::queue<int> q;

    visited[s] = 1;
    dist[s] = 0;

    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();

        if(s == e){
            std::cout<<dist[e];
            break;
        }

        next = s * 2;
        if(next >=0 && next <= 100000 && !visited[next]){
            visited[next] = 1;
            dist[next] = dist[s] + 1;
            q.push(next);
        }

        next = s + 1;
        if (next >= 0 && next <= 100000 && !visited[next]){
            visited[next] = 1;
            dist[next] = dist[s] + 1;
            q.push(next);
        }

        next = s - 1;
        if (next >= 0 && next <= 100000 && !visited[next]){
            visited[next] = 1;
            dist[next] = dist[s] + 1;
            q.push(next);
        }
    }
}

int main(){
    int s,e;
    std::cin>>s>>e;
    BFS(s,e);
    return 0;
}