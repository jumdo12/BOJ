#include <iostream>
#include <map>
#include <queue>

int min = 99;
int board[101] = {0};
int visited[101] = {0};

void BFS(){
    std::queue<std::pair<int,int>> q;

    q.push({1,0});

    while(!q.empty()){
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(curr > 100) continue;
        else if(curr == 100){
            min = cnt;
            break;
        }

        if(!visited[curr]){
            visited[curr] = 1;

            if(board[curr]){
                curr = board[curr];
            }

            for(int i=1; i<=6; i++){
                q.push({curr + i , cnt + 1});
            }
        }
    }
}

int main(){
    int ladder,snake;
    std::cin>>ladder>>snake;

    for(int i=0; i<ladder + snake; i++){
        int temp;
        std::cin>>temp;
        std::cin>>board[temp];
    }

    BFS();

    std::cout<<min;

    return 0;
}