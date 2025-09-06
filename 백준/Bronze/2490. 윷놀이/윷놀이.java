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
        for(int i=0; i<3; i++){
            String line = bf.readLine();
            String[] split = line.split(" ");

            long count = Arrays.stream(split).filter(str -> str.equals("0")).count();

            if(count == 1) {
                sb.append("A").append("\n");
            }
            if(count == 2) {
                sb.append("B").append("\n");
            }
            if(count == 3) {
                sb.append("C").append("\n");
            }
            if(count == 4) {
                sb.append("D").append("\n");
            }
            if(count == 0) {
                sb.append("E").append("\n");
            }
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
