import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] solution(long n) {
        String str = String.valueOf(n);
        int[] answer = new int[str.length()];
        
        StringBuilder sb = new StringBuilder(str);
        str = sb.reverse().toString();
        
        int idx = 0;
        for(String num : str.split("")){
            answer[idx++] = Integer.parseInt(num); 
        }
        
        return answer;
    }
}