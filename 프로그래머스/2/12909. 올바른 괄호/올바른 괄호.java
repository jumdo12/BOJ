import java.util.*;

class Solution {
    boolean solution(String s) {
        
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            char currChar = s.charAt(i);
            
            if(currChar == '(') {
                count++;
            }
            else {
                if(count == 0) {
                    return false;
                }
                else {
                    count--;
                }
            }
        }
        
        if(count != 0) {
            return false;
        }
        
        return true;
    }
}
