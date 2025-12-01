import java.util.*;

class Solution {
    
    // 상, 하, 좌, 우
    public int[] dr = {-1, 1, 0, 0};
    public int[] dc = {0, 0, -1, 1};
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        
        // 방문 여부 체크 (다시 false로 돌리지 않음!)
        boolean[][] visited = new boolean[n][m];
        
        // BFS를 위한 큐: {행, 열, 현재까지의 거리}
        Queue<int[]> q = new LinkedList<>();
        
        // 시작점 넣기
        q.offer(new int[]{0, 0, 1});
        visited[0][0] = true;
        
        while(!q.isEmpty()) {
            int[] current = q.poll();
            int r = current[0];
            int c = current[1];
            int count = current[2];
            
            // 목적지 도착 시 바로 리턴 (이게 최단거리임이 보장됨)
            if(r == n - 1 && c == m - 1) {
                return count;
            }
            
            for(int i = 0; i < 4; i++) {
                int nextR = r + dr[i];
                int nextC = c + dc[i];
                
                // 범위 벗어나거나, 벽이거나(0), 이미 방문했으면 스킵
                if(nextR < 0 || nextC < 0 || nextR >= n || nextC >= m) continue;
                if(maps[nextR][nextC] == 0) continue;
                if(visited[nextR][nextC]) continue;
                
                // 방문 처리 후 큐에 삽입
                visited[nextR][nextC] = true; 
                q.offer(new int[]{nextR, nextC, count + 1});
            }
        }
        
        // 큐가 빌 때까지 도달 못했으면 갈 수 없는 곳
        return -1;
    }
}