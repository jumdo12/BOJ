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
        String line = bf.readLine();
        String[] parsed= line.split(" ");

        Deque<Balloon> balloons = new ArrayDeque<>();

        for(int i=0; i<n; i++){
            Balloon balloon = new Balloon(i+1, Integer.parseInt(parsed[i]));
            balloons.addLast(balloon);
        }

        while(!balloons.isEmpty()) {
            Balloon balloon = balloons.removeFirst();
            int idx = balloon.idx;

            sb.append(idx).append(" ");
            int num = balloon.num;
            
            if(balloons.isEmpty()){
                break;
            }

            if(num < 0) {
                for(int j=0; j < -1 * num; j++){
                    Balloon last = balloons.removeLast();
                    balloons.addFirst(last);
                }
            }

            if(num > 0) {
                for(int j=0; j < num - 1; j++){
                    Balloon first = balloons.removeFirst();
                    balloons.addLast(first);
                }
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }

    public static class Balloon {
        public int idx;
        public int num;

        public Balloon(int idx, int num) {
            this.idx = idx;
            this.num = num;
        }
    }
}