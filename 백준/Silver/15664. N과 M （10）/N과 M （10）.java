import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N,M;
    static int arr[];
    static int ans[];
    static int visited[];

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception{
        StringTokenizer sTokenizer;

        sTokenizer = new StringTokenizer(br.readLine());

        N = Integer.parseInt(sTokenizer.nextToken());
        M = Integer.parseInt(sTokenizer.nextToken());

        arr = new int [N];
        ans = new int [M];
        visited = new int [N];

        sTokenizer = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(sTokenizer.nextToken());
        }

        Arrays.sort(arr);

        DFS(0,0);
        wr.flush();

        wr.close();
    }

    public void DFS(int curr,int idx) throws Exception{
        int before = -1;

        if(curr == M){
            for(int i=0; i<M; i++){
                wr.write(ans[i] + " ");
            }
            wr.write("\n");
        } 
        else {
            for(int i=idx; i<N; i++){
                if(visited[i] != 0) continue;

                if(before != arr[i]){
                    ans[curr] = arr[i];
                    before = arr[i];
                    visited[i] = 1;
                    DFS(curr+1,i+1);
                    visited[i] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}