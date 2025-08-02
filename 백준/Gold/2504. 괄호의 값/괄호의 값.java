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
        Stack<String> stack = new Stack<>();
        String line = bf.readLine();
        String[] split = line.split("");

        for(int i=0; i<split.length; i++) {
            String token = split[i];

            if(token.equals("(") || token.equals("[")) {
                stack.push(token);
            }
            if(token.equals(")") || token.equals("]")) {
                if(!isNums(stack.peek())) {
                    if(token.equals(")") && !stack.peek().equals("(")) {
                        sb.append("0");
                        return sb;
                    }

                    if(token.equals("]") && !stack.peek().equals("[")) {
                        sb.append("0");
                        return sb;
                    }

                    if(token.equals(")")) {
                        stack.pop();
                        stack.push("2");
                    }
                    else{
                        stack.pop();
                        stack.push("3");
                    }
                    continue;
                }

                int sum = 0;

                while(isNums(stack.peek())) {
                    sum += Integer.parseInt(stack.pop());
                }

                if(token.equals(")") && !stack.peek().equals("(")) {
                    sb.append("0");
                    return sb;
                }

                if(token.equals("]") && !stack.peek().equals("[")) {
                    sb.append("0");
                    return sb;
                }

                if(token.equals(")")){
                    stack.pop();
                    stack.push(String.valueOf(sum * 2));
                }

                if(token.equals("]")) {
                    stack.pop();
                    stack.push(String.valueOf(sum * 3));
                }
            }
        }

        int sum = 0;
        while(!stack.isEmpty()) {
            sum += Integer.parseInt(stack.pop());
        }

        sb.append(sum);
        return sb;
    }

    public static boolean isNums(String number) {
        return !number.equals("(") && !number.equals("[");
    }
}