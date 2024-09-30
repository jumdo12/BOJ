import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N,M,cnt;
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
        arr = Arrays.stream(arr).distinct().toArray();
        cnt = arr.length;

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
            for(int i=0; i<cnt; i++){
                if(curr == 0){
                    ans[curr] = arr[i];
                    DFS(curr+1);
                }
                else{
                    if(ans[curr-1] <= arr[i]){
                        ans[curr] = arr[i];
                        DFS(curr+1);
                    }                    
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}