import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M, D;
    static int[][] originalGrid;
    static int maxKilled = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        originalGrid = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                originalGrid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        selectArchers(0, 0, new int[3]);

        System.out.println(maxKilled);
    }

    static void selectArchers(int depth, int start, int[] archers) {
        if (depth == 3) {
            int killed = simulate(archers);
            maxKilled = Math.max(maxKilled, killed);
            return;
        }

        for (int i = start; i < M; i++) {
            archers[depth] = i;
            selectArchers(depth + 1, i + 1, archers);
        }
    }

    static int simulate(int[] archers) {
        int[][] grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            System.arraycopy(originalGrid[i], 0, grid[i], 0, M);
        }

        int totalKilled = 0;

        while (hasEnemies(grid)) {
            List<int[]> targets = new ArrayList<>();

            for (int archer : archers) {
                int[] target = findTarget(grid, N, archer);
                if (target != null) {
                    targets.add(target);
                }
            }

            for (int[] target : targets) {
                if (grid[target[0]][target[1]] == 1) {
                    grid[target[0]][target[1]] = 0;
                    totalKilled++;
                }
            }

            moveEnemies(grid);
        }

        return totalKilled;
    }

    static int[] findTarget(int[][] grid, int archerRow, int archerCol) {
        int minDistance = Integer.MAX_VALUE;
        int[] target = null;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == 1) {
                    int distance = Math.abs(archerRow - r) + Math.abs(archerCol - c);

                    if (distance <= D) {
                        if (distance < minDistance ||
                                (distance == minDistance && (target == null || c < target[1]))) {
                            minDistance = distance;
                            target = new int[]{r, c};
                        }
                    }
                }
            }
        }

        return target;
    }

    static boolean hasEnemies(int[][] grid) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    return true;
                }
            }
        }
        return false;
    }

    static void moveEnemies(int[][] grid) {
        for (int r = N - 1; r >= 0; r--) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    if (r + 1 < N) {
                        grid[r + 1][c] = 1;
                    }
                }
            }
        }
    }
}
