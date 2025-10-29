#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dw[8] = {-1,0,1,0,-1,1,1,-1};
int dh[8] = {0,-1,0,1,-1,-1,1,1};
int m[51][51] = {0};
bool visited[51][51] = {0};

int cnt = 0;
int w, h;

bool isOut(int currW, int currH) {
    return currW < 0 || currW >= w || currH < 0 || currH >= h;
}

void bfs(int w, int h) {
    queue<pair<int,int>> q;

    q.push({w,h});
    visited[h][w] = true;

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        for(int i=0; i<8; i++) {
            int currH = curr.second + dh[i];
            int currW = curr.first + dw[i];

            if(!isOut(currW, currH) && !visited[currH][currW] && m[currH][currW] == 1) {
                visited[currH][currW] = true;
                q.push({currW, currH});
            } 
        }
    }
}

int main() {
    while(1) {
        cin >> w >> h;

        if(w == 0 && h == 0) {
            break;
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                int tmp;
                cin >> tmp;

                m[i][j] = tmp;
                visited[i][j] = false;
            }
        }

        cnt = 0;

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(m[i][j] == 1 && !visited[i][j]) {
                    bfs(j,i);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}