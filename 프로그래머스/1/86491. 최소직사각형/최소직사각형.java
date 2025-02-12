import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int maxWidth = 0;
        int maxHeight = 0;
        
        for(int[] arr : sizes){
            int w = arr[0];
            int h = arr[1];
            
            int longSide = Math.max(w,h);
            int shortSide = Math.min(w,h);
            
            maxWidth = Math.max(maxWidth,longSide);
            maxHeight = Math.max(maxHeight,shortSide);
        }
        
        return maxWidth * maxHeight;
    }
}