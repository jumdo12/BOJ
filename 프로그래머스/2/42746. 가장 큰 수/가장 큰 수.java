import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        List<String> list = new ArrayList<>();
        
        for(int i=0; i<numbers.length; i++) {
            list.add(String.valueOf(numbers[i]));
        }
        
        list.sort((a,b) -> {
            return (b+a).compareTo(a+b);
        });
    
        StringBuilder sb = new StringBuilder();
        for(String str : list) {
            sb.append(str);
        }
        
        if(sb.toString().startsWith("0")){
            return String.valueOf(0);
        }
        return sb.toString();
    }
}