import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
public class Main {

    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        try{
            solve(bf,bw,sb);
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }

    public static void solve(BufferedReader bf, BufferedWriter bw, StringBuilder sb) throws IOException {
        int n = Integer.parseInt(bf.readLine());

        Double[] arr = new Double[n];

        Stack<Double> stack = new Stack<>();
        String line = bf.readLine();

        for(int i=0; i<n; i++){
            arr[i] = Double.parseDouble(bf.readLine());
        }

        String[] parsed=  line.split("");



        for(int i=0; i<parsed.length; i++){
            String s = parsed[i];

            if(s.contains("+") || s.contains("-") || s.contains("*") || s.contains("/")) {
                Double pop2 = stack.pop();
                Double pop1 = stack.pop();

                if(s.equals("+")) {
                    stack.push(pop1 + pop2);
                }
                if(s.equals("-")) {
                    stack.push(pop1 - pop2);
                }
                if(s.equals("*")) {
                    stack.push(pop1 * pop2);
                }
                if(s.equals("/")) {
                    stack.push(pop1 / pop2);
                }
            }
            else {
                int idx = s.charAt(0) - 'A';
                stack.push(arr[idx]);
            }
        }

        Double ans = stack.pop();
        sb.append(String.format(("%.2f"), ans));

        bw.write(sb.toString());
        bw.flush();
    }
}