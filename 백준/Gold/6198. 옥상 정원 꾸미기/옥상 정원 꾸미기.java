import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        String line = bf.readLine();
        int n = Integer.parseInt(line);

        List<Integer> list = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String line1 = bf.readLine();
            list.add(Integer.parseInt(line1));
        }

        int[] view = new int[n];
        Stack<Integer> stack = new Stack<>();
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) {
                view[i] = 0;
                stack.push(i);
                continue;
            }

            while(!stack.isEmpty() && list.get(i) > list.get(stack.peek())) {
                int peek = stack.pop();
                view[i] += view[peek] + 1;
            }

            stack.push(i);
        }

        long sum = 0;
        for(int i=0; i<n; i++) {
            sum += view[i];
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
