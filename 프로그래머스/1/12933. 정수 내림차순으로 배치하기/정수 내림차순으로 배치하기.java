import java.util.*;

class Solution {
    public long solution(long n) {
        String str = "";
        
        int[] arr = new int[10];
        
        while(n > 0){
            int num = (int)(n % 10);
            arr[num]++;
            n /= 10;
        }
        
        for(int i=9; i >= 0; i--){
            for(int j=0; j<arr[i]; j++){
                str += i;
            }
        }
        
        return Long.parseLong(str);
    }
}