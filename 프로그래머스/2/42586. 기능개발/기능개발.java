import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] times = new int[speeds.length];
        for(int i=0; i<speeds.length; i++) {
            int tmp = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
            // 만약 100 - 30 = 70 / 30 = 2.xxx -> 3일
            // 즉 올림을 해야함.
            times[i] = tmp;
        }
        
        LinkedList<Integer> stack = new LinkedList<>();
        List<Integer> ans = new ArrayList<>();
        
        stack.addLast(times[0]);        
        int max = times[0];
        for(int i=1; i<speeds.length; i++) {
            if(times[i] > max) {
                max = times[i];
                ans.add(stack.size());
                stack.clear();
            }
            
            stack.addLast(times[i]);
        }
        
        if(!stack.isEmpty()){
            ans.add(stack.size());
        }
        
        return ans.stream().mapToInt(i -> i).toArray();
    }
}

/*

 각 기능은 100%가 되어야한다?
 개발 속도가 다 다르다.. 뒤에 있는 기능이 앞에 있는 기능이랑 같이 배포된다?
 
 진도와 개발 속도 배열이 주어진다. 배포마다 몇 개의 기능이 배포되는가.
 
 배포는 하루 끝에 된다.
 
 95 -> 5일
 90 -> 10일
 99 -> 1일
 99 -> 1일
 80 -> 20일
 99 -> 1일
 
 얼마나 걸리는지 기준으로 봐야함
 5 10 1 1 20 10
 뒤에가 더 큰가?
 yes -> 갯수 출력 후 pop
 뒤에가 작은가?, 같다면?
 no -> push
 
*/