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
            int row = Integer.parseInt(parsedLine[0]);
            int col = Integer.parseInt(parsedLine[1]);

            for(int i=0; i<row; i++){
                line = br.readLine();;
                StringBuilder sb = new StringBuilder();
                sb.append(line);
                sb.reverse();
                System.out.println(sb);
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}