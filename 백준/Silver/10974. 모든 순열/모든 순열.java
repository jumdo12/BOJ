import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Comparator;

public class Main {
    static int N,M,cnt;
    static int arr[];
    static int sorted[];
    static int visited[];
    static int ans[];

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception{
        StringTokenizer sTokenizer;

        sTokenizer = new StringTokenizer(br.readLine());

        N = Integer.parseInt(sTokenizer.nextToken());

        arr = new int [N];
        ans = new int [N];
        sorted = new int [N];
        visited = new int [N+1];

        DFS(0);

        wr.flush();
        wr.close();
    }

    public void DFS(int curr) throws Exception{
        if(curr == N){
            for(int i=0; i<N; i++){
                wr.write(ans[i] + " ");
            }
            wr.write("\n");
        }
        else{
            for(int i=1; i<= N; i++){
                if(visited[i] == 0){
                    visited[i] = 1;
                    ans[curr] = i;
                    DFS(curr+1);
                    visited[i] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}