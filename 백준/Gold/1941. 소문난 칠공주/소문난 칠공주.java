import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    private static char[][] map = new char[5][5];
    private static int[] dr = {-1, 0, 1, 0};
    private static int[] dc = {0, 1, 0, -1};
    private static int[] selected = new int[7];

    private static int ans;

    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<5; i++) {
            map[i] = br.readLine().toCharArray();
        }

        solve(0,0,0);

        System.out.println(ans);
    }

    private static void solve(final int depth, final int curr, final int sCount) {
        if(depth == 7) {
            if(isConnected()) {
                ans++;
            }
            return;
        }

        for(int i = curr; i < 25; i++) {
            selected[depth] = i;

            int row = i / 5;
            int col = i % 5;

            if(map[row][col] == 'S') {
                solve(depth + 1, i + 1,  sCount + 1);
            } else {
                if(depth - sCount < 3) {
                    solve(depth + 1, i + 1,  sCount);
                }
            }
        }
    }

    private static boolean isConnected() {
        boolean[] visited = new boolean[7];
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(0);
        visited[0] = true;
        int count = 1;

        while(!queue.isEmpty()) {
            Integer currIdx = queue.poll();
            int curr = selected[currIdx];

            int row = curr / 5;
            int col = curr % 5;

            for(int i=0; i<4; i++) {
                int nextRow = row + dr[i];
                int nextCol = col + dc[i];

                if(nextRow < 0 || nextRow >= 5 || nextCol < 0 || nextCol >= 5) {
                    continue;
                }

                int nextPosition = nextRow * 5 + nextCol;

                for(int j=0; j<7; j++) {
                    if(!visited[j] && selected[j] == nextPosition) {
                        visited[j] = true;
                        queue.add(j);
                        count++;
                    }
                }
            }
        }

        return count == 7;
    }
}
