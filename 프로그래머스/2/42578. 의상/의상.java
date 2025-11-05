import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<>();
        
        for(int i=0; i<clothes.length; i++) {
            String category = clothes[i][1];
            
            if(map.containsKey(category)) {
                map.put(category, map.get(category) + 1);
                continue;
            }
            
            map.put(category, 1);
        }
                
        int answer = 1;
        for(var entry : map.entrySet()) {
            answer *= (entry.getValue() + 1);
        }
    
        return answer - 1;
    }
}