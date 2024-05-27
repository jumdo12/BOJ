#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX_POS 25

std::vector<int> ans;
int map[25][25] = { 0 };
int visited[25][25] = { 0 };
int cnt;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y);

int main() {
	int N;
	std::cin >> N;
	std::string str;
	std::vector<int> ans;
	for (int i = 0; i < N; i++) {
		std::cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(visited[i][j] == 0 && map[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	
	std::cout << ans.size() << '\n';
	std::sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << '\n';
	}

	return 0;
}

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int _x = x + dx[i];
		int _y = y + dy[i];

		if (_x < 0 || _x >= MAX_POS || _y < 0 || _y >= MAX_POS) continue;
		if (!visited[_x][_y] && map[_x][_y]) {
			dfs(_x, _y);
		}
	}
}