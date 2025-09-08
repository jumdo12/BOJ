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
        String line = bf.readLine();

        int n = Integer.parseInt(line);

        line = bf.readLine();
        String[] split = line.split(" ");
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            list.add(Integer.parseInt(split[i]));
        }

        line = bf.readLine();
        int target = Integer.parseInt(line);

        list.sort(Integer::compareTo);

        int sum = 0;
        int leftIdx = 0;
        int rightIdx = list.size() - 1;

        while(leftIdx < rightIdx){
            int left = list.get(leftIdx);
            int right = list.get(rightIdx);

            if(left + right == target) {
                sum ++;
                leftIdx++;
                rightIdx--;
            }
            else if(left + right > target) {
                rightIdx--;
            }
            else {
                leftIdx++;
            }
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
