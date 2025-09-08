import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        String line = bf.readLine();
        String line1 = bf.readLine();

        int[] leftAlpha = new int[26];
        int[] rightAlpha = new int[26];

        for(int i=0; i<line.length(); i++) {
            leftAlpha[line.charAt(i)-'a']++;
        }

        for (int i=0; i<line1.length(); i++) {
            rightAlpha[line1.charAt(i)-'a']++;
        }

        int sum = 0;
        for(int i=0; i<26; i++) {
            int dist = Math.abs(leftAlpha[i] - rightAlpha[i]);
            sum += dist;
        }

        sb.append(sum);
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
