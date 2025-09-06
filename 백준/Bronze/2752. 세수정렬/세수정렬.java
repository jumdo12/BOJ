import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        List<Integer> list = new ArrayList<>();

        String line = bf.readLine();
        String[] split = line.split(" ");

        for(String s : split) {
            list.add(Integer.parseInt(s));
        }

        list.sort(Integer::compareTo);

        for(int i=0; i<list.size(); i++) {
            int num = list.get(i);
            sb.append(num);
            sb.append(" ");
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
