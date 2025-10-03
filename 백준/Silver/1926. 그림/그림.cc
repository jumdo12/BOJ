#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[501][501] = {0};
bool visited[501][501];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int N;
int M;
int paintCount = 0;
int areaMax = 0;

class Node {
private:
    int row;
    int col;

public:
    Node(int row, int col) : row(row), col(col) {}

    Node move(int row, int col) {
        return Node(this->row + row, this->col + col);
    }

    int getRow () {return row;}
    int getCol() {return col;}
};

bool isOutOfBoundary(Node n) {
    int row = n.getRow();
    int col = n.getCol();

    return row < 0 || row >= N || col < 0 || col >= M;
}

int bfs(int row, int col) {
    queue<Node> q;
    q.push(Node(row,col));
    visited[row][col] = true;

    int area = 0;

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            auto next = curr.move(dr[i], dc[i]);
            if (!isOutOfBoundary(next) && !visited[next.getRow()][next.getCol()] && arr[next.getRow()][next.getCol()] == 1) {
                q.push(next);
                visited[next.getRow()][next.getCol()] = true;
            }
        }
    }

    return area;
}

int main() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visited[i][j] && arr[i][j] == 1) {
                int area = bfs(i, j);
                paintCount++;
                areaMax = max(areaMax, area);
            } 
        }
    }

    cout << paintCount << endl;
    cout << areaMax;

    return 0;
}
