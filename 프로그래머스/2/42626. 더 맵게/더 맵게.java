import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=0; i<scoville.length; i++) {
            pq.add(scoville[i]);
        }
        
        int count = 0;
        while(pq.size() >= 2 && pq.peek() < K) {
            int min = pq.poll();
            int nextMin = pq.poll();
            
            pq.add(min + nextMin * 2);
            count++;
        }
        
        if(pq.peek() < K){
            return -1;
        }
        
        return count;
    }
}