import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        String line = bf.readLine();
        int n = Integer.parseInt(line);

        line = bf.readLine();
        String[] split = line.split(" ");
        Set<Integer> set = new HashSet<>();
        for(int i=0; i<n; i++){
            set.add(Integer.parseInt(split[i]));
        }

        line = bf.readLine();
        int target = Integer.parseInt(line);

        int sum = 0;
        for(int i=0; i<n; i++){
            int num = Integer.parseInt(split[i]);
            int need = target - num;

            if(set.contains(need)){
                sum++;
            }
        }
        
        sb.append(sum / 2);
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
