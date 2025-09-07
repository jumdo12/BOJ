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
        int[] arr = new int[50];
        for(int i=1; i<=20; i++) {
            arr[i] = i;
        }

        for(int i=0; i<10; i++) {
            String line = bf.readLine();
            String[] split = line.split(" ");

            int left = Integer.parseInt(split[0]);
            int right = Integer.parseInt(split[1]);

            while(left < right) {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left ++;
                right--;
            }

        }

        for(int i=1; i<=20; i++) {
            sb.append(arr[i]).append(" ");
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
