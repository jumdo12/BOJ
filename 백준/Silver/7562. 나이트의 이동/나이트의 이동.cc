#include <iostream>
#include <queue>
#include <map>

int size;
std::pair<int,int> s,e;
int visited[300][300] = {0};
int dist[300][300] = {0};

int dx[8] = {1,2,2,1,-1,-2,-1,-2};
int dy[8] = {-2,-1,1,2,2,1,-2,-1};

void init();
void BFS();

int main(){
    int cnt;
    std::cin>>cnt;
    for(int i=0; i<cnt; i++){
        std::cin>>size;
        std::cin>>s.first>>s.second;
        std::cin>>e.first>>e.second;
        init();
        BFS();
        std::cout<<dist[e.first][e.second]<<'\n';
    }
    return 0;
}

void init(){
    for (int i = 0; i < 300; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            dist[i][j] = visited[i][j] = 0;
        }
    }
}

void BFS(){
    std::pair<int,int> next;
    std::queue<std::pair<int,int>> q;

    visited[s.first][s.second] = 1;
    dist[s.first][s.second] = 0;

    q.push(s);

    while(!q.empty()){
        s = q.front();
        q.pop();

        if(s.first == e.first && s.second == e.second) break;

        for(int i=0; i<8; i++){
            next.first = s.first + dx[i];
            next.second = s.second + dy[i];

            if(next.first >= 0 && next.first < size && next.second >= 0 && next.second < size && !visited[next.first][next.second]){
                q.push(next);
                visited[next.first][next.second] = 1;
                dist[next.first][next.second] = dist[s.first][s.second] + 1;
            }
        }
    }
}