import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve() {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            int N = Integer.parseInt(bf.readLine());
            List<Deque<Integer>> queues = new ArrayList<>();
            for(int i=0; i<N; i++){
                Deque<Integer> queue = new LinkedList<>();
                queues.add(queue);
            }

            for(int i=0; i<N; i++){
                String line = bf.readLine();
                String[] parsedLine = line.split(" ");
                for(int j=0; j<N; j++){
                    queues.get(j).addFirst(Integer.parseInt(parsedLine[j]));
                }
            }

            int cnt = 0;
            while(true){
                int max = Integer.MIN_VALUE;
                int maxIdx = 0;

                for(int i=0; i<N; i++){
                    Queue<Integer> q = queues.get(i);
                    if(q.peek() > max){
                        max = q.peek();
                        maxIdx = i;
                    }
                }

                if(cnt == N-1){
                    System.out.println(max);
                    break;
                }

                cnt++;
                Queue<Integer> q = queues.get(maxIdx);
                q.poll();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}