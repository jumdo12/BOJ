import java.util.*;

class Solution {
    
    public static class Task implements Comparable<Task>{
        public int duration;
        public int startTime;
        public int idx;
        
        public Task(int startTime, int endTime, int idx) {
            this.duration = endTime - startTime;
            this.startTime = startTime;
            this.idx = idx;
        }
        
        @Override
        public int compareTo(Task other) {
            if(this.duration == other.duration) {
                if(this.startTime == other.startTime) {
                    return this.idx - other.idx;
                }
                
                return this.startTime - other.startTime;
            }
            
            return this.duration - other.duration;
        }
    }
    
    public int solution(int[][] jobs) {
        PriorityQueue<Task> pq = new PriorityQueue<>();
        List<Task> tasks = new ArrayList<>();
        
        for(int i=0; i<jobs.length; i++) {
            int startTime = jobs[i][0];
            int duration = jobs[i][1];
            int idx = i;
            
            Task task = new Task(startTime, startTime + duration, idx);
            tasks.add(task);
        }
        
        tasks.sort((a,b) -> {
          return a.startTime - b.startTime;  
        });
        
        int currTime = 0;
        int currIdx = 0;
        int ans = 0;
        int count = 0;
        while(count < tasks.size()) {
            while(currIdx < tasks.size() && tasks.get(currIdx).startTime <= currTime) {
                pq.add(tasks.get(currIdx));
                currIdx++;
            }
            
            if(pq.isEmpty()) {
                currTime = tasks.get(currIdx).startTime;
            } else {
                Task task = pq.poll();
                
                ans += (currTime - task.startTime + task.duration);
                currTime += task.duration;
                count++;
            }
        }
        
        return ans / tasks.size();
    }
}