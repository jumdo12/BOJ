import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int days = Integer.parseInt(br.readLine());
            int[] T = new int[days];
            int[] V = new int[days];
            int[] dp = new int[days+1];

            for(int i=0; i<days; i++){
                String line = br.readLine();
                String[] parsedLine = line.split(" ");

                T[i] = Integer.parseInt(parsedLine[0]);
                V[i] = Integer.parseInt(parsedLine[1]);
            }

            int max = 0;
            for(int i=0; i<days; i++){
                dp[i] = Math.max(max,dp[i]);
                int nextDay = i + T[i];
                if(nextDay <= days){
                    dp[nextDay] = Math.max(Math.max(max, dp[i] + V[i]),dp[nextDay]);
                }
                max = Math.max(max,dp[i]);
            }

            System.out.println(Arrays.stream(dp).max().getAsInt());
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}