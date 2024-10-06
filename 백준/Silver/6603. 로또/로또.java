import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main{
    static final int SIZE = 6;

    static int N;
    static int ans[];
    static int arr[];
    static int visited[];
    static int minCost = Integer.MAX_VALUE;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception{
        while(true){
            StringTokenizer sTokenizer = new StringTokenizer(br.readLine());            
            N = Integer.parseInt(sTokenizer.nextToken());

            if(N == 0) break;

            visited = new int[N];
            arr = new int[N];
            ans = new int [SIZE];

            for(int i=0; i<N; i++){
                arr[i] = Integer.parseInt(sTokenizer.nextToken());       
            }

            DFS(0, 0);
            wr.write("\n");

            wr.flush();
        }
        wr.close();
    }

    public void DFS(int curr,int idx) throws Exception{
        if(curr == SIZE){
            for(int i=0; i<SIZE; i++){
                wr.write(ans[i] + " ");
            }
            wr.write("\n");
        }
        else{
            for(int i=idx; i<N; i++){
                ans[curr] = arr[i];
                DFS(curr+1,i+1);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}