import java.util.*;

class Solution {
    public int[] solution(int[] num_list, int n) {
        List<Integer> numbers = new ArrayList<>();
        for(int i = n; i<num_list.length; i++){
            numbers.add(num_list[i]);
        }
        for(int i=0; i<n; i++){
            numbers.add(num_list[i]);
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}