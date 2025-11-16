import java.util.*;

class Solution {
    public int solution(int N, int number) {
        Map<Integer, Set<Long>> map = new HashMap<>();
        
        if(number == N) {
            return 1;
        }
        
        Long sum = 0L;
        for(int currCount = 1; currCount <= 8; currCount++) {
            Set<Long> set = new HashSet<>();
            map.put(currCount, set);
            
            sum *= 10;
            sum += N;
            
            if(sum == number) {
                return currCount;
            }
            set.add(sum);
            
            for(int i = currCount-1; i > 0; i--) {
                int left = i;
                int right = currCount - i;
                
                var leftSet = map.get(left);
                var rightSet = map.get(right);
                
                for(var leftNum : leftSet) {
                    for(var rightNum : rightSet) {
                        var num = leftNum + rightNum;
                        if(num == number) {
                            return currCount;
                        }
                        set.add(num);
                        
                        num = leftNum - rightNum;
                        if(num == number) {
                            return currCount;
                        }
                        set.add(num);
                        
                        num = leftNum * rightNum;
                        if(num == number) {
                            return currCount;
                        }
                        set.add(num);
                        
                        if(rightNum == 0){
                            continue;
                        }
                        num = leftNum / rightNum;
                        if(num == number) {
                            return currCount;
                        }
                        set.add(num);
                    }
                }
            } 
        }
        
        return -1;
    }
}
