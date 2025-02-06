import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int s = arr.length;
        int e = -1;
        
        for(int i=0; i<arr.length; i++){
            if(arr[i] == 2){
                if(s > i) s = i;
                if(e < i) e = i;
            }
        }
        
        for(int i=s; i <= e; i++){
            list.add(arr[i]);
        }
        
        if(list.isEmpty()) list.add(-1);
        
        return list.stream().mapToInt(i->i).toArray();
    }
}