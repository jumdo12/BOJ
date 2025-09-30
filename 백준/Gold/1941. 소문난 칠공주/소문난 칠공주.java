import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static char[][] map = new char[5][5];
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 5; i++) {
            map[i] = br.readLine().toCharArray();
        }

        // 25개 칸 중 7개를 선택하는 조합
        combination(new int[7], 0, 0, 0);
        
        System.out.println(answer);
    }

    // 25개 칸 중 7개를 선택하는 조합 (0~24 인덱스)
    static void combination(int[] selected, int start, int depth, int sCnt) {
        if (depth == 7) {
            // 이다솜파가 4명 이상인지 확인
            if (sCnt >= 4) {
                // 7명이 인접해있는지 BFS로 확인
                if (isConnected(selected)) {
                    answer++;
                }
            }
            return;
        }

        for (int i = start; i < 25; i++) {
            selected[depth] = i;
            int row = i / 5;
            int col = i % 5;
            
            // 이다솜파면 sCnt 증가
            if (map[row][col] == 'S') {
                combination(selected, i + 1, depth + 1, sCnt + 1);
            } else {
                // 임도연파가 4명 이상이면 가지치기
                if (depth - sCnt < 3) {
                    combination(selected, i + 1, depth + 1, sCnt);
                }
            }
        }
    }

    // 선택된 7개 칸이 모두 인접해있는지 BFS로 확인
    static boolean isConnected(int[] selected) {
        boolean[] visited = new boolean[7];
        Queue<Integer> queue = new LinkedList<>();
        
        queue.offer(0);
        visited[0] = true;
        int count = 1;

        while (!queue.isEmpty()) {
            int curr = queue.poll();
            int currPos = selected[curr];
            int currRow = currPos / 5;
            int currCol = currPos % 5;

            for (int i = 0; i < 4; i++) {
                int nextRow = currRow + dx[i];
                int nextCol = currCol + dy[i];

                if (nextRow < 0 || nextRow >= 5 || nextCol < 0 || nextCol >= 5) {
                    continue;
                }

                int nextPos = nextRow * 5 + nextCol;

                // 선택된 7개 중에서 아직 방문하지 않은 인접한 칸 찾기
                for (int j = 0; j < 7; j++) {
                    if (!visited[j] && selected[j] == nextPos) {
                        visited[j] = true;
                        queue.offer(j);
                        count++;
                    }
                }
            }
        }

        return count == 7;
    }
}