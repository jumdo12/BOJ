import java.util.*;

class Solution {
    
    class Node {
        
        public int x;
        public int y;
        public int count;
        
        public Node(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
    }
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int[][] map = new int[106][106];
        boolean[][] visited = new boolean[102][102];
        
        for(int i=0; i<rectangle.length; i++) {
            int leftX = rectangle[i][0] * 2;
            int leftY = rectangle[i][1] * 2;
            int rightX = rectangle[i][2] * 2;
            int rightY = rectangle[i][3] * 2;
            
            for(int y  = leftY; y <= rightY; y++) {
                for(int x = leftX; x <= rightX; x++) {
                    map[x][y] = 1;
                }
            }
        }
        
        for(int i=0; i<rectangle.length; i++) {
            int leftX = rectangle[i][0] * 2 + 1;
            int leftY = rectangle[i][1] * 2 + 1;
            int rightX = rectangle[i][2] * 2 - 1;
            int rightY = rectangle[i][3] * 2 - 1;
            
            for(int y  = leftY; y <= rightY; y++) {
                for(int x = leftX; x <= rightX; x++) {
                    map[x][y] = 0;
                }
            }
        }
        
        int[] dx = new int[]{-1,0,1,0};
        int[] dy = new int[]{0,1,0,-1};
        
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(characterX * 2, characterY * 2, 0));
        visited[characterX * 2][characterY * 2] = true;
        
        while(!q.isEmpty()) {
            Node curr = q.poll();
            
            if(curr.x == itemX * 2 && curr.y == itemY * 2) {
                return curr.count;
            }
            
            for(int i=0; i<4; i++) {
                int nextX = curr.x + dx[i];
                int nextY = curr.y + dy[i];
                
                int nextMoveX = curr.x + dx[i] * 2;
                int nextMoveY = curr.y + dy[i] * 2;
                
                if(map[nextX][nextY] == 0) {
                    continue;
                }
                
                if(visited[nextMoveX][nextMoveY] == true) {
                    continue;
                }
                
                q.offer(new Node(nextMoveX, nextMoveY, curr.count + 1));
                visited[nextMoveX][nextMoveY] = true;
            }
        }
        
        return 0;
    }
}

/*

1. 사각형 1로 채우기
    1. 2배 해상도 늘려서 채우기
2. 사각형 내부 지우기
    1. 태두리만 남기기
3. BFS 순회
    1. 2씩 넘어가기

1. 겹쳐진 부분 지워야함
2. 내부에 필요없어진 간선도 지워야함

갈 수 있는 부분만 1로 채우기로하자

1. 모든 부분을 1로 채우기
2. 내부만 0으로 지우기

만약
1 1
1 1
ㄷ 인 경우 벽을 뜷고 가는 경우가 생김
1,1 2,2
->
2,2 4,4로 변환

4,2 4,3 4,4
3,2     3,4
2,2 2,3 2,4

이러면 되긴 함
이동할때 2씩 이동하면 문제 없음

*/
