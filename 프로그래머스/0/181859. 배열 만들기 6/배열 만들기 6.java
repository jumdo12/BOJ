import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        for(int num : arr){
            if(stack.isEmpty()){
                stack.push(num);
            }
            else{
                int peek = stack.peek();
                if(peek == num){
                    stack.pop();
                }
                else{
                    stack.push(num);
                }
            }
        }
        
        if(stack.isEmpty()) stack.push(-1);
        
        return stack.stream().mapToInt(i->i).toArray();
    }
}