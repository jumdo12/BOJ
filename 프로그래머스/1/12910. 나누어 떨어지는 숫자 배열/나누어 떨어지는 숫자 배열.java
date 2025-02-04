import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        List<Integer> numbers = new ArrayList<>();
        
        for(int num : arr){
            if(num % divisor == 0){
                numbers.add(num);
            }
        }
        
        if(numbers.isEmpty()) numbers.add(-1);
        
        numbers.sort(Comparator.naturalOrder());
        return numbers.stream().mapToInt(i->i).toArray();
    }
}