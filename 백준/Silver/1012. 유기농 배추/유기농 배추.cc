#include <iostream>

int flag;
int map[50][50] = {0};
int visited[50][50] = {0};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int Maxx, Maxy;

void dfs(int x, int y){
    if(x < 0 || x >= Maxx || y < 0 || y >= Maxy)    return;

    if(!visited[x][y] && map[x][y]){
        visited[x][y] = 1;
        flag = 1;

        for(int i=0; i<4; i++){
            dfs(x+dx[i],y+dy[i]);
        }
    }

    return;
}

void init_map(){
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main(){
    int N; std::cin>>N;
    int ans = 0;

    while(N--){
        init_map();
        ans = 0;

        int cnt,x,y;
        std::cin>>Maxx>>Maxy>>cnt;
        
        for(int i=0; i<cnt; i++){
            std::cin>>x>>y;
            map[x][y] = 1;
        }

        for(int i=0; i<Maxx; i++){
            for(int j=0; j<Maxy; j++){
                flag = 0;
                dfs(i,j);
                if(flag){
                    ans++;
                    flag = 0;
                }
            }
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}