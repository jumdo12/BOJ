import java.util.*;

class Solution {
    public int[] solution(int start_num, int end_num) {
        List<Integer> numbers = new ArrayList<>();
        for(int i=start_num; i <=end_num; i++){
            numbers.add(i);
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}