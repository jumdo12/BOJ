import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();
        int length = progresses.length;
        
        for(int i=0; i<length; i++) {
            int rst = 100 - progresses[i];
            int days = (rst + speeds[i] - 1) / speeds[i];
            
            list.add(days);
        }
    
        int curr = list.get(0);
        int count = 1;
        List<Integer> ans = new ArrayList<>();
        for(int i=1; i < length; i++) {
            if(list.get(i) > curr) { // 나보다 클때
                curr = list.get(i);
                ans.add(count);
                count = 1;
            } else {    // 나보다 작을 때
                count++;
            }
        }
        
        ans.add(count);
        
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
