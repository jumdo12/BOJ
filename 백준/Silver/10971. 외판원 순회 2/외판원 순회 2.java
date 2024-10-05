import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int N; // 도시의 수
    static int g[][]; // 그래프
    static boolean visited[]; // 방문한 도시 기록
    static int minCost = Integer.MAX_VALUE; // 최소 비용

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception {
        // 입력 처리
        StringTokenizer sTokenizer = new StringTokenizer(br.readLine());
        N = Integer.parseInt(sTokenizer.nextToken());

        g = new int[N][N];
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            sTokenizer = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                g[i][j] = Integer.parseInt(sTokenizer.nextToken());
            }
        }

        // 각 도시를 출발점으로 설정하여 DFS 탐색
        for (int i = 0; i < N; i++) {
            visited[i] = true; // 출발점 방문 처리
            DFS(i, i, 1, 0); // 출발점에서 DFS 탐색 시작
            visited[i] = false; // 탐색 후 초기화
        }

        wr.write(minCost + "\n"); // 최소 비용 출력
        wr.flush();
        wr.close();
    }

    // DFS 함수
    public void DFS(int start, int curr, int depth, int cost) throws Exception {
        // 모든 도시를 방문한 경우
        if (depth == N) {
            // 다시 출발 도시로 돌아갈 수 있는지 확인
            if (g[curr][start] != 0) {
                minCost = Math.min(minCost, cost + g[curr][start]); // 최소 비용 갱신
            }
            return;
        }

        // 다른 도시로 이동
        for (int i = 0; i < N; i++) {
            if (!visited[i] && g[curr][i] != 0) { // 방문하지 않은 도시 및 경로가 존재하는 경우
                visited[i] = true; // 방문 표시
                DFS(start, i, depth + 1, cost + g[curr][i]); // 다음 도시로 이동
                visited[i] = false; // 백트래킹: 방문 해제
            }
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solve();
    }
}
