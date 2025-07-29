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
        Stack<Integer> stack = new Stack<>();
        int cnt = Integer.parseInt(bf.readLine());

        for(int i=0; i<cnt; i++) {
            String cmd = bf.readLine();

            if(cmd.contains("push")) {
                int num = Integer.parseInt(cmd.split(" ")[1]);
                stack.push(num);
            }

            if(cmd.contains("pop")) {
                sb.append(stack.isEmpty() ? -1 : stack.pop()).append("\n");
            }

            if(cmd.contains("size")) {
                sb.append(stack.size()).append("\n");
            }

            if(cmd.contains("empty")) {
                sb.append(stack.isEmpty() ? 1 : 0).append("\n");
            }

            if(cmd.contains("top")) {
                sb.append(stack.isEmpty() ? -1 : stack.peek()).append("\n");
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }
}