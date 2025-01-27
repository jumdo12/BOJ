import java.util.*;

class Solution {
    public int[] solution(int[] num_list, int n) {
        List<Integer> numbers = new ArrayList<>();
        
        for(int i=0; i<num_list.length; i += n){
            numbers.add(num_list[i]);
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}