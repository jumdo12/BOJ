import java.util.*;
class Solution {
    private boolean isOdd(int a){
        return a % 2 != 0;
    }
    
    public int solution(int a, int b) {
        if(isOdd(a) && isOdd(b)){
            return a*a + b*b;
        }
        else if(!isOdd(a) && !isOdd(b)){
            return Math.abs(a-b);
        }
        
        
        return 2 * (a+b);
    }
}