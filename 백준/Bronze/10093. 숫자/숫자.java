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
        String line = bf.readLine();
        String[] split = line.split(" ");

        long left = Long.parseLong(split[0]);
        long right = Long.parseLong(split[1]);
        
        long tmp = left;
        if(left > right) {
            left = right;
            right = tmp;
        }

        if(left == right) {
            sb.append(0).append("\n");
            return;
        }

        sb.append(right - left - 1).append("\n");

        for(long i = left + 1L; i < right; i++) {
            sb.append(i).append(" ");
        }
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
