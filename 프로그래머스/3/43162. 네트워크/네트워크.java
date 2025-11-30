import java.util.*;

class Solution {
    public static int count = 0;
    
    public void dfs(int n, int[][] computers, boolean[] visited, int curr) {
        visited[curr] = true;
        
        for(int i=0; i<n; i++) {
            if(curr == i) {
                continue;
            }
            
            if(visited[i]) {
                continue;
            }
            
            if(computers[curr][i] == 1 && computers[i][curr] == 1) {
                dfs(n, computers, visited, i);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        boolean[] visited = new boolean[n];
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(n,computers,visited, i);  
                count++;
            }
        }
        
        return count;
    }
}

/*

A외 B가 직접 연결 후
B와 C가 직접 연결되어 있는 경우 
A와 C가 서로 정보교환을 할  수 있다.
같은 네트워크

단방향으로 되어있는데, 양방향 이어야 가능
그러니까 양방향이어야 이동 가능한데,
visited 표시 해줘서 같은 네트워크 인지 판별
영역표시 어캐?
1,1,1,1,2,2,2,2,2 일케 해도 되긴 하니까 일케 하자 걍



*/
