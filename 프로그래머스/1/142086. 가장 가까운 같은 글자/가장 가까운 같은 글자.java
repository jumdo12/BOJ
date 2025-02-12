import java.util.*;

class Solution {
    public int[] solution(String s) {
        List<Integer> answer = new ArrayList<>();
        int[] arr = new int[26];
        
        for(int i=0; i<26; i++){
            arr[i] = -1;
        }
        
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            int dst = ch - 'a';
            
            if(arr[dst] == -1){
                answer.add(arr[dst]);
                arr[dst] = i;
            } else {
                answer.add(i - arr[dst]);
                arr[dst] = i;
            }
        }
         
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}