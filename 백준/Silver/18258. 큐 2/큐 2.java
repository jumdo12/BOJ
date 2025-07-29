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
        try{
            solve(bf,bw);
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }

    public static void solve(BufferedReader bf, BufferedWriter bw) throws IOException {
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(bf.readLine());
        Deque<Integer> deque = new ArrayDeque<>();

        for(int i=0; i<n; i++) {
            String cmd = bf.readLine();

            if(cmd.contains("push")) {
                int num = Integer.parseInt(cmd.split(" ")[1]);
                deque.addLast(num);
            }
            if(cmd.contains("pop")) {
                if(deque.isEmpty()) {
                    sb.append("-1\n");
                    continue;
                }
                sb.append(deque.removeFirst()).append("\n");
            }

            if(cmd.contains("size")){
                sb.append(deque.size()).append("\n");
            }
            if(cmd.contains("empty")){
                sb.append(deque.isEmpty() ? 1 : 0).append("\n");
            }
            if(cmd.contains("front")) {
                if(deque.isEmpty()) {
                    sb.append("-1\n");
                    continue;
                }

                sb.append(deque.peekFirst()).append("\n");
            }
            if(cmd.contains("back")) {
                if(deque.isEmpty()) {
                    sb.append("-1\n");
                    continue;
                }

                sb.append(deque.peekLast()).append("\n");
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }
}