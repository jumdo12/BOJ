#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
#include <string>

char board[1001][1001] = {0};
int dist[1001][1001][2] = {0};

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int ROW,COL;

int BFS(){
    std::queue<std::tuple<int,int,int>> q;
    q.push(std::make_tuple(0,0,0));
    dist[0][0][0] = 1;

    while(!q.empty()){
        int r,c,f;
        std::tie(r,c,f) = q.front();

        if(r + 1 == ROW && c + 1 == COL){
            return dist[r][c][f];
        }

        q.pop();

        for(int i=0; i<4; i++){
            int nr,nc;
            nr = r + dr[i];
            nc = c + dc[i];

            if(nr >= 0 && nr < ROW && nc >= 0 && nc < COL && !dist[nr][nc][f]){
                if(board[nr][nc] == '1' && !f){
                    q.push(std::make_tuple(nr,nc,1));
                    dist[nr][nc][1] = dist[r][c][0] + 1;
                } else if(board[nr][nc] =='0' && !dist[nr][nc][f]){
                    q.push(std::make_tuple(nr, nc, f));
                    dist[nr][nc][f] = dist[r][c][f] + 1;
                }  
            }    
        }
    }
    return -1;
}

int main(){
    std::cin>>ROW>>COL;
    for(int i=0; i<ROW; i++){
        std::string temp;
        std::cin>>temp;
        for(int j=0; j<COL; j++){
            board[i][j] = temp[j];
        }
    }

    std::cout<<BFS();
    return 0;
}