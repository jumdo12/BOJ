import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        String line = bf.readLine();
        int[] arr = new int[10];

        for(int i=0; i< line.length(); i++){
            int digit = line.charAt(i) - '0';

            if(digit == 9) {
                arr[6]++;
            }else {
                arr[digit]++;
            }
        }

        int max = 0;

        arr[6] = (arr[6] + 1) / 2;

        for(int i=0; i<10; i++) {
            if(max < arr[i]) {
                max = arr[i];
            }
        }

        sb.append(max);
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
