import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Integer> q = new ArrayDeque<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int i=0; i<priorities.length; i++) {
            q.add(priorities[i]);
            pq.add(priorities[i]);
        }
        
        int count = 1;
        while(!q.isEmpty()) {
            int front = q.poll();
            
            if(front == pq.peek()) {
                if(location == 0) {
                    break;
                } else {
                    count++;
                    location--;
                    pq.poll();
                }
            } else {
                if(location == 0) {
                    location = q.size();
                }
                else {
                    location--;
                    
                }
                q.add(front);
            }
        }
        
        return count;
    }
}
