#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N;
char m[101][101] = {0};

bool r_g_b_visited[101][101] = {false};
bool rg_b_visited[101][101] = {false};

int dr[4] = {0,-1,0,1};
int dc[4] = {-1,0,1,0};

bool isOut(int row, int col) {
    return row < 0 || row >= N || col < 0 || col >= N;
}

void r_g_b_bfs(int row, int col) {
    queue<pair<int,int>> q;

    q.push({row,col});
    r_g_b_visited[row][col] = true;

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        int currRow = curr.first;
        int currCol = curr.second;

        for(int i=0; i<4; i++) {
            int nextRow = currRow + dr[i];
            int nextCol = currCol + dc[i];

            if(!isOut(nextRow, nextCol) && 
            !r_g_b_visited[nextRow][nextCol] && 
            m[nextRow][nextCol] == m[currRow][currCol]) {
                r_g_b_visited[nextRow][nextCol] = true;
                q.push({nextRow, nextCol});
            }
        }
    }
}

void rg_b_bfs(int row, int col) {
    queue<pair<int, int>> q;

    q.push({row, col});
    rg_b_visited[row][col] = true;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int currRow = curr.first;
        int currCol = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = currRow + dr[i];
            int nextCol = currCol + dc[i];

            if (!isOut(nextRow, nextCol) &&
                !rg_b_visited[nextRow][nextCol] &&
                !(
                    (m[currRow][currCol] == 'R' && m[nextRow][nextCol] == 'B') ||
                    (m[currRow][currCol] == 'G' && m[nextRow][nextCol] == 'B') ||
                    (m[currRow][currCol] == 'B' && ((m[nextRow][nextCol] == 'R') || m[nextRow][nextCol] == 'G'))
                )
            )
            {
                rg_b_visited[nextRow][nextCol] = true;
                q.push({nextRow, nextCol});
            }
        }
    }
}

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char tmp;

            cin >> tmp;

            m[i][j] = tmp;
        }
    } 

    int r_g_b_count = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!r_g_b_visited[i][j]) {
                r_g_b_bfs(i,j);
                r_g_b_count++;
            }
        }
    }

    int rg_b_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!rg_b_visited[i][j])
            {
                rg_b_bfs(i, j);
                rg_b_count++;
            }
        }
    }

    cout << r_g_b_count << " " << rg_b_count;

    return 0;
}
