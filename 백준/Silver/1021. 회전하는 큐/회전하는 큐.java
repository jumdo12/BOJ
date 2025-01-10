import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void leftSpin(Deque<Integer> q, int cnt){
        for(int i=0; i<cnt; i++){
            q.add(q.poll());
        }
    }

    private static void rightSpin(Deque<Integer> q, int cnt){
        for(int i=0; i<cnt; i++){
            q.addFirst(q.pollLast());
        }
    }

    private static int findTargetIdx(Deque<Integer> q, int target){
        int idx = 0;
        for(Integer item : q){
            if(item == target){
                return idx;
            }
            idx++;
        }
        return -1;
    }

    private static void solve() {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Deque<Integer> queue = new ArrayDeque<>();
        List<Integer> targetNumbers = new ArrayList<>();

        try {
            String line = bf.readLine();
            int queueSize = Integer.parseInt(line.split(" ")[0]);
            int targetCnt = Integer.parseInt(line.split(" ")[1]);

            line = bf.readLine();
            String[] parsedLine = line.split(" ");

            for(int i=1; i<=queueSize; i++){
                queue.add(i);
            }

            for(String token : parsedLine){
                targetNumbers.add(Integer.parseInt(token));
            }

            int cnt = 0;
            for(int i=0; i<targetCnt; i++){
                int target = targetNumbers.get(i);

                while(target != queue.peek()){
                    int targetIdx = findTargetIdx(queue,target);

                    if(queue.size() / 2 < targetIdx){ // on right side
                        rightSpin(queue,queue.size()-targetIdx);
                        cnt += queue.size() - targetIdx;
                    } else {
                        leftSpin(queue,targetIdx);
                        cnt += targetIdx;
                    }
                }

                queue.poll();
            }

            System.out.println(cnt);
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}