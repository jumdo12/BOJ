import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int list[];
    static int ans[];
    static int visited[];

    static int N;
    static int M;

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer sTokenizer = new StringTokenizer(br.readLine());

        
        N = Integer.parseInt(sTokenizer.nextToken());
        M = Integer.parseInt(sTokenizer.nextToken());

        list = new int[N];
        ans = new int[M];
        visited = new int[N];

        for(int i=0; i<N; i++){
            visited[i] = 0;
        }

        sTokenizer = new StringTokenizer(br.readLine());

        for(int i=0; i<N; i++){
            list[i] = Integer.parseInt(sTokenizer.nextToken());
        }

        Arrays.sort(list);

        dfs(0);
    }

    public static void dfs(int curr){
        if(curr == M){
            for(int num : ans){
                System.out.print(num + " ");
            }
            System.out.println();
        } else {
            for(int i=0; i < N; i++){
                if(visited[i] == 0){
                    visited[i] = 1;
                    ans[curr] = list[i];
                    dfs(curr+1);
                    visited[i] = 0;
                }
            }
        }
    } 
    
    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}
