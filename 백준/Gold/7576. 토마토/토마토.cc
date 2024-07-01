#include <iostream>
#include <queue>
#include <map>

int tomatos[1001][1001] = {0};
int visited[1001][1001] = {0};
int dist[1001][1001] = {0};

int tx[4] = {0,1,0,-1};
int ty[4] = {-1,0,1,0};

int max;
int xsize, ysize;

void BFS();
int is_full();

int main(){
    std::cin>>xsize>>ysize;

    for(int i=1; i<=ysize; i++){
        for(int j=1; j<=xsize; j++){
            std::cin>>tomatos[j][i];
        }
    }
    BFS();
    return 0;
}

void BFS(){
    int x, y;
    std::queue<std::pair<int,int>> q;
    std::pair<int,int> p;

    for(int i=1; i <= ysize; i++){
        for(int j=1; j<= xsize; j++){
            if(tomatos[j][i] == 1){
                visited[j][i] = 1;
                q.push({j, i});
            }
        }
    }

    while(!q.empty()){
        p = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            x = p.first + tx[i];
            y = p.second + ty[i];

            if(x >=1 && x <= xsize && y >= 1 && y <= ysize){
                if(!visited[x][y] && tomatos[x][y] == 0){
                    tomatos[x][y] = 1;
                    visited[x][y] = 1;
                    dist[x][y] = dist[p.first][p.second] + 1;
                    if(max < dist[x][y]) max = dist[x][y];

                    q.push({x,y});
                }
            }
        }
    }

    if(is_full()){
        std::cout<< max;
    } else{
        std::cout << -1;
    }
}

int is_full(){
    for(int i = 1; i<=ysize; i++){
        for(int j=1; j<=xsize; j++){
            if(tomatos[j][i] == 0) return 0;
        }
    }
    return 1;
}