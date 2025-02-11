import java.util.*;

class Solution {
    private String convertTo3(int n){
        StringBuilder sb = new StringBuilder();
        while(n != 0){
            sb.append(n % 3);
            n /= 3;
        }
        return sb.reverse().toString();
    }
    
    private int convertToDec(String str){
        int sum = 0;
        
        StringBuilder sb = new StringBuilder();
        sb.append(str);
        
        str = sb.toString();
        System.out.println(str);
        for(int i=0; i<str.length(); i++){
            sum += (int)Math.pow(3,i) * (str.charAt(i) - '0'); 
        }
        
        return sum;
    }
    
    public int solution(int n) {
        int answer = 0;
        
        String str = convertTo3(n);
        answer = convertToDec(str);
        
        return answer;
    }
}