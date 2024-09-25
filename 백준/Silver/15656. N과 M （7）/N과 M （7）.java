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

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception{
        StringTokenizer sTokenizer;

        sTokenizer = new StringTokenizer(br.readLine());

        N = Integer.parseInt(sTokenizer.nextToken());
        M = Integer.parseInt(sTokenizer.nextToken());

        arr = new int [N];
        ans = new int [M];

        sTokenizer = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(sTokenizer.nextToken());
        }

        Arrays.sort(arr);

        DFS(0);
        wr.flush();

        wr.close();
    }

    public void DFS(int curr) throws Exception{
        if(curr == M){
            for(int i=0; i<M; i++){
                wr.write(ans[i] + " ");
            }
            wr.write("\n");
        } 
        else {
            for(int i=0; i<N; i++){
                ans[curr] = arr[i];
                DFS(curr+1);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}