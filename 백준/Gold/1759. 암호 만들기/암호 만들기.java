import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main{
    static final int SIZE = 6;

    static int L,C;
    static char ans[];
    static char arr[];

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception{
        StringTokenizer sTokenizer = new StringTokenizer(br.readLine());            
        L = Integer.parseInt(sTokenizer.nextToken());
        C = Integer.parseInt(sTokenizer.nextToken());

        ans = new char[L];
        arr = new char[C];

        sTokenizer = new StringTokenizer(br.readLine());     
        for(int i=0; i<C; i++){
            String token = sTokenizer.nextToken();
            arr[i] = token.charAt(0);    
        }

        Arrays.sort(arr);

        DFS(0,0,0,0);
        wr.flush();
        wr.close();
    }

    public void DFS(int curr ,int idx, int cnt, int gatherCount) throws Exception{
        if(curr == L){
            if(cnt >= 2 && gatherCount >= 1){
                for(int i=0; i<L; i++){
                    wr.write(ans[i]);
                }
                wr.write("\n");
            }
        }
        else{
            for(int i=idx; i<C; i++){
                ans[curr] = arr[i];
                if(isGether(arr[i])) DFS(curr+1,i+1,cnt,gatherCount+1);
                else DFS(curr+1,i+1,cnt+1,gatherCount);
            }
        }
    }

    public boolean isGether(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }


    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}