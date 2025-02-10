import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> numbers = new ArrayList<>();
        
        int prev = -1;
        for(int num : arr){
            if(num != prev){
                prev = num;
                numbers.add(num);
            }
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}