import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        int min = Integer.MAX_VALUE;
        int sum = 0;

        for(int i=0; i<7; i++ ){
            String line = bf.readLine();
            int num = Integer.parseInt(line);

            if(num % 2 == 0) {
                continue;
            }

            sum += num;

            if(min > num){
                min = num;
            }
        }

        if(sum == 0) {
            sb.append("-1");
            return;
        }

        sb.append(sum).append("\n");
        sb.append(min);
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
