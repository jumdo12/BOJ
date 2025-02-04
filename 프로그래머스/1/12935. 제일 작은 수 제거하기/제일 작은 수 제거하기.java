import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> numbers = new ArrayList<>();
        
        int minIdx = 0;
        int min = arr[0];
        
        if(arr.length == 1){
            numbers.add(-1);
            return numbers.stream().mapToInt(i->i).toArray();
        }
        else{
            for(int i=0; i<arr.length; i++){
                if(arr[i] < min){
                    min = arr[i];
                    minIdx = i;
                }
            }
            
            for(int i=0; i<arr.length; i++){
                if(i != minIdx){
                    numbers.add(arr[i]);
                }
            }
            
            return numbers.stream().mapToInt(i->i).toArray();
        }
    }
}