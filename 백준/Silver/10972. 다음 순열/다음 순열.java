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
    static int ans[];

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    public void solve() throws Exception{
        int idx = -1;
        StringTokenizer sTokenizer;

        sTokenizer = new StringTokenizer(br.readLine());

        N = Integer.parseInt(sTokenizer.nextToken());

        arr = new int [N];
        ans = new int [N];
        sorted = new int[N];

        sTokenizer = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(sTokenizer.nextToken());
        }

        Integer[] intArr = Arrays.stream(arr)
                                .boxed()
                                .toArray(Integer[]::new);

        for(int i=N-1; i>0; i--){
            if(arr[i] < arr[i-1]) continue;
            idx = i-1;
            break;
        }

        if(idx == -1){
            wr.write("-1");
        }
        else {
            for(int i=N-1; i > idx; i--){
                if(intArr[i] > intArr[idx]){
                    int temp = intArr[i];
                    intArr[i] = intArr[idx];
                    intArr[idx] = temp;
                    break;
                }
            }
            Arrays.sort(intArr,idx+1,N);
            
            for(int i=0; i<N; i++){
                wr.write(intArr[i] + " ");
            }
        }

        wr.flush();
        wr.close();
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}