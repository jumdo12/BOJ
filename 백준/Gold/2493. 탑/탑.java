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
            StringBuilder sb = solve(bf);

            bw.write(sb.toString());
            bw.flush();
        }catch (Exception e){
            System.out.println(0);
        }
    }

    public static StringBuilder solve(BufferedReader bf) throws IOException {
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(bf.readLine());

        String line = bf.readLine();
        String[] parsed = line.split(" ");

        Stack<Integer> stack = new Stack<>();
        List<Integer> ans = new ArrayList<>();

        for(int i=0; i<n; i++) {
            int height = Integer.parseInt(parsed[i]);

            if(i == 0) {
                stack.push(i);
                ans.add(i);
                continue;
            }

            if(Integer.parseInt(parsed[stack.peek()]) > height) {
                ans.add(stack.peek() + 1);
                stack.push(i);
                continue;
            }

            while(!stack.isEmpty() && Integer.parseInt(parsed[stack.peek()]) <= height) {
                stack.pop();
            }

            if(stack.isEmpty()) {
                ans.add(0);
            }
            else {
                ans.add(stack.peek() + 1);
            }
            stack.push(i);
         }

        for (Integer an : ans) {
            sb.append(an).append(" ");
        }

        return sb;
    }
}