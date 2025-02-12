import java.util.*;

class Solution {

    public int[] solution(int[] numbers) {
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        
        for(int i=0; i<numbers.length - 1; i++){
            for(int j=i+1; j<numbers.length; j++){
                int sum = numbers[i] + numbers[j];
                if(!set.contains(sum)) {
                    list.add(sum);
                    set.add(sum);
                }
            }
        }
        
        
        list.sort(Comparator.naturalOrder());
        
        return list.stream().mapToInt(i->i).toArray();
    }
}