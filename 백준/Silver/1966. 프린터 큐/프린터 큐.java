import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static class Paper{
        int priority;

        public Paper(int priority) {
            this.priority = priority;
        }
    }

    private static void solve(){
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            int cnt = Integer.parseInt(bf.readLine());
            for(int i=0; i<cnt; i++){
                Queue<Paper> queue = new LinkedList<>();
                
                String line = bf.readLine();
                int paperCnt = Integer.parseInt(line.split(" ")[0]);
                int targetCnt = Integer.parseInt(line.split(" ")[1]);
                Paper targetPaper = null;

                line = bf.readLine();
                String[] parsedPriority = line.split(" ");

                for(int j=0; j<paperCnt; j++){
                    Paper paper = new Paper(Integer.parseInt(parsedPriority[j]));
                    if(j == targetCnt){
                        targetPaper = paper;
                    }
                    queue.add(paper);
                }

                int printOrder = 0;
                while(!queue.isEmpty()){
                    Paper currPaper = queue.poll();
                    Paper heightPriorityPaper = currPaper;
                    for(Paper paper : queue){
                        if(heightPriorityPaper.priority < paper.priority)
                            heightPriorityPaper = paper;
                    }

                    if(currPaper.priority == heightPriorityPaper.priority){
                        printOrder++;
                        if(targetPaper == currPaper){
                            System.out.println(printOrder);
                            break;
                        }
                    } else {
                        queue.add(currPaper);
                    }
                }
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}