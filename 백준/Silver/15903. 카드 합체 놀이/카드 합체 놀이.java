import javax.security.auth.callback.CallbackHandler;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = br.readLine();
            String[] parsedLine = line.split(" ");

            int n = Integer.parseInt(parsedLine[0]);
            int m = Integer.parseInt(parsedLine[1]);

            line = br.readLine();
            parsedLine = line.split(" ");

            PriorityQueue<Long> numbers = new PriorityQueue<>();

            for(String num : parsedLine){
                numbers.add(Long.parseLong(num));
            }

            for(int i=0; i<m; i++){
                Long min1 = numbers.poll();
                Long min2 = numbers.poll();

                numbers.add(min1 + min2);
                numbers.add(min1 + min2);
            }

            Long sum = 0L;
            while(!numbers.isEmpty()){
                sum += numbers.poll();
            }
            System.out.println(sum);
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}