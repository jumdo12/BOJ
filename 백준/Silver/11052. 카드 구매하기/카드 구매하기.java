import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        String line = br.readLine();

        String[] split = line.split(" ");
        List<Integer> list = new ArrayList<>();

        list.add(0);
        for(String s : split) {
            list.add(Integer.parseInt(s));
        }

        int[] dp = new int[n + 2];

        for(int i=1; i <= n; i++) {
            dp[i] = list.get(i);

            for(int j = i - 1; j >= 0; j--) {
                int dst = i - j;
                dp[i] = Math.max(dp[i], dp[j] + list.get(dst));
            }
        }

        sb.append(dp[n]);
    }

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try{
            solve(br);

            bw.write(sb.toString());
            bw.flush();
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
