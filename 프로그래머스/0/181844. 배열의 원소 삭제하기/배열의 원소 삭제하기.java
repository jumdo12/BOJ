import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        List<Integer> numbers = new ArrayList<>();
        
        for(int num : arr){
            boolean flag = false;
            
            for(int delNum : delete_list){
                if(num == delNum){
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                numbers.add(num);
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}