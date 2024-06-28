#include <iostream>
#include <string>
#include <queue>
#include <vector>

const int MAX = 100; // 문제의 최대 크기

char Maze[MAX + 2][MAX + 2];
int visited[MAX + 2][MAX + 2];
int dist[MAX + 2][MAX + 2];

int ROW, COL;

int tr[4] = {-1, 0, 1, 0};
int tc[4] = {0, 1, 0, -1};

void func(int r, int c) {
    int _r, _c;
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> temp;

    temp.first = r;
    temp.second = c;

    q.push(temp);
    visited[r][c] = 1;
    dist[r][c] = 1;

    while (!q.empty()) {
        temp = q.front(); // 현재 위치
        q.pop();

        if (temp.first == ROW && temp.second == COL) break;

        for (int i = 0; i < 4; i++) {
            _r = temp.first + tr[i];
            _c = temp.second + tc[i];

            if (_r >= 1 && _r <= ROW && _c >= 1 && _c <= COL && !visited[_r][_c] && Maze[_r][_c] == '1') {
                visited[_r][_c] = 1;
                dist[_r][_c] = dist[temp.first][temp.second] + 1;
                q.push(std::make_pair(_r, _c));
            }
        }
    }
}

int main() {
    std::cin >> ROW >> COL;

    for (int i = 1; i <= ROW; i++) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < COL; j++) {
            Maze[i][j + 1] = str[j];
        }
    }

    func(1, 1);

    std::cout << dist[ROW][COL];

    return 0;
}
