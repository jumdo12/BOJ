import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        Stack<Integer> stk = new Stack<>();
        
        int idx = 0;
        
        while(idx < arr.length){
            if(stk.isEmpty()){
                stk.push(arr[idx]);
                idx++;
            } else {
                if(stk.peek() >= arr[idx]){
                    stk.pop();
                } else{
                    stk.push(arr[idx]);
                    idx++;
                }
            }
        }
        
        return stk.stream().mapToInt(i->i).toArray();
    }
}