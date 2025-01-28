import java.util.*;

class Solution {
    public int[] solution(int[] num_list, int n) {
        List<Integer> numbers = new ArrayList<>();
        
        for(int i=n-1; i<num_list.length; i++){
            numbers.add(num_list[i]);
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}