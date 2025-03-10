import java.util.*;

class Solution {
    public int solution(int[] numbers) {
        int sum = 0;
        Set<Integer> set = new HashSet<>();
        for(int num : numbers){
            set.add(num);
        }
        
        for(int i=0; i<10; i++){
            if(!set.contains(i)) sum += i;
        }
        
        return sum;
    }
}