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

        for(int i=0; i<n; i++) {
            String line = bf.readLine();
            String ans = checkFunc(line);
            sb.append(ans).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }

    public static String checkFunc(String line) {
        Stack<String> stack = new Stack<>();

        for(int i=0; i<line.length(); i++) {
            String c = String.valueOf(line.charAt(i));

            if(c.equals("(")) {
                stack.push(c);
            }

            if(c.equals(")")) {
                if(stack.isEmpty()) {
                    return "NO";
                }

                stack.pop();
            }
        }

        if(!stack.isEmpty()) {
            return "NO";
        }
        return "YES";
    }
}