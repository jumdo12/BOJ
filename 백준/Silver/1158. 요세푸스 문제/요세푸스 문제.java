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
        String line = bf.readLine();
        int k = Integer.parseInt(line.split(" ")[0]);
        int n = Integer.parseInt(line.split(" ")[1]);

        Deque<Integer> deque = new ArrayDeque<>();

        for(int i=1; i<=k; i++){
            deque.addLast(i);
        }

        sb.append("<");
        while(deque.size() != 1){
            for(int i=0; i<n-1; i++){
                Integer first = deque.removeFirst();
                deque.addLast(first);
            }

            Integer item = deque.removeFirst();
            sb.append(item).append(", ");
        }

        sb.append(deque.removeFirst()).append(">");

        bw.write(sb.toString());
        bw.flush();
    }
}