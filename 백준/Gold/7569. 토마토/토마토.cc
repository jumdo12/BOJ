#include <iostream>
#include <queue>
#include <map>

int row,col,height;
int Max = 0;
int dist[101][101][101] = {0};
int tomatoes[101][101][101];

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int dh[2] = {-1,1};

std::queue<std::pair<std::pair<int,int>,int>> q;

int max(int a, int b){
    return a > b ? a : b;
}

void BFS(){
    int r,c,h;
    while(!q.empty()){
        r = q.front().first.first;
        c = q.front().first.second;
        h = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            if(tomatoes[nr][nc][h] == 0){
                tomatoes[nr][nc][h] = 1;
                q.push({{nr, nc}, h});
                dist[nr][nc][h] = dist[r][c][h] + 1;
                Max = max(Max,dist[nr][nc][h]);
            }
        }

        for(int i=0; i<2; i++){
            int nh = h + dh[i];

            if(nh < 0 || nh >= height) continue;
            if(tomatoes[r][c][nh] == 0){
                tomatoes[r][c][nh] = 1;
                q.push({{r, c}, nh});
                dist[r][c][nh] = dist[r][c][h] + 1;
                Max = max(Max, dist[r][c][nh]);
            }
        }   
    }
}

int main(){
    std::cin>>col>>row>>height;
    for(int i=0; i<height; i++){
        for(int j=0; j<row; j++){
            for(int k=0; k<col; k++){
                std::cin>>tomatoes[j][k][i];
                if(tomatoes[j][k][i] == 1){
                    q.push({{j,k},i});
                }
            }
        }
    }
    BFS();

    int flag = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            for(int k=0; k<height; k++){
                if(tomatoes[i][j][k] == 0) flag = 1;
            }
        }
    }

    if(flag == 1) std::cout<< -1;
    else    std::cout << Max;

    return 0;
}