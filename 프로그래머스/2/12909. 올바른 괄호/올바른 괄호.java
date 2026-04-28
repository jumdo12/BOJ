import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        LinkedList<String> list = new LinkedList<>();
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            
            if(ch == '(') {
                list.add("(");
            }
            else if(ch == ')') {
                if(list.isEmpty()) {
                    return false;
                }
                
                if(list.peekLast().equals(")")) {
                    return false;
                }
                
                list.pollLast();
            }
        } 
        
        if(!list.isEmpty()){
            return false;
        }
        
        return true;
    }
}
