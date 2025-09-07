import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        String line = bf.readLine();
        int n = Integer.parseInt(line);

        for(int i=0; i<n; i++) {
            line = bf.readLine();

            String[] split = line.split(" ");

            int[] left = new int[26];
            int[] right = new int[26];

            for(int j=0; j<split[0].length(); j++) {
                left[split[0].charAt(j) - 'a']++;
            }

            for(int j=0; j<split[1].length(); j++) {
                right[split[1].charAt(j) - 'a']++;
            }

            boolean flag = false;
            for(int j=0; j<26; j++) {
                if(left[j] != right[j]) {
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                sb.append("Possible");
                sb.append("\n");
                continue;
            }
            sb.append("Impossible");
            sb.append("\n");
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
