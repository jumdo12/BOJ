#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int board[101][101] = {0};
bool visited[101][101] = {false};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, M, K;

bool isOut(int x, int y){
    return x >= M || x < 0 || y >= N || y < 0;
}

void fill(int leftDownX, int leftDownY, int rightUpX, int rightUpY) {
    for(int i = leftDownY; i < rightUpY; i++) {
        for(int j = leftDownX; j < rightUpX; j++) {
            board[j][i] = 1;
        }
    }
}

int area(int x, int y){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    int size = 1;
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nextX = curr.first + dx[i];
            int nextY = curr.second + dy[i];

            if(!isOut(nextX, nextY) && !visited[nextX][nextY] && board[nextX][nextY] == 0) {
                size++;
                visited[nextX][nextY] = true;
                q.push({nextX, nextY});
            }
        }
    }

    return size;
}

int main() {
    cin >> N >> M >> K;
    
    for(int i=0; i<K; i++) {
        int leftDownX;
        int leftDownY;

        int rightUpX;
        int rightUpY;

        cin >> leftDownX >> leftDownY;
        cin >> rightUpX >> rightUpY;

        fill(leftDownX, leftDownY, rightUpX, rightUpY);
    }

    vector<int> ans;

    for(int i = N-1; i >= 0; i--) {
        for(int j=0; j<M; j++) {
            if(!visited[j][i] && board[j][i] == 0) {
                ans.push_back(area(j,i));
            }
        }
    }

    cout << ans.size() << endl;

    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
