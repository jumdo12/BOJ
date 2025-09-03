import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.stream.Collectors;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
public class Main {

    static StringBuilder sb = new StringBuilder();

    static int n;
    static List<String> list = new ArrayList<>();
    static int max = Integer.MIN_VALUE;

    public static void solve(BufferedReader bf) throws IOException {

        String line = bf.readLine();
        n = Integer.parseInt(line);

        line = bf.readLine();
        String[] split = line.split("");

        for(String s : split) {
            list.add(s);
        }

        dfs(1, getNumber(0));
        sb.append(max);
    }

    public static int getNumber(int idx) {
        return Integer.parseInt(list.get(idx));
    }

    public static void dfs(int curr, int sum) {
        if(curr + 1 >= n) {
            max = Math.max(max, sum);
            return;
        }

        String op = list.get(curr);
        int right = getNumber(curr + 1);
        int next = calc(sum, op, right);

        dfs(curr + 2, next);

        int nextOpIdx = curr + 2;
        if(nextOpIdx < n) {
            String nextOp = list.get(nextOpIdx);

            int leftNumber = getNumber(nextOpIdx - 1);
            int rightNumber = getNumber(nextOpIdx + 1);
            int nextParen = calc(leftNumber, nextOp, rightNumber);

            int parenResult = calc(sum, op, nextParen);
            dfs(nextOpIdx + 2, parenResult);
        }
    }

    public static int calc(int left, String op, int right) {
        if(op.equals("+")) {
            return left + right;
        }
        if(op.equals("-")) {
            return left - right;
        }

        return left * right;
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
