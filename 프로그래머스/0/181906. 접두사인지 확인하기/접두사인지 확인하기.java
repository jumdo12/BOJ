import java.util.*;

class Solution {
    public int solution(String my_string, String is_prefix) {
        Set<String> set = new HashSet<>();
        for(int i=0; i<my_string.length(); i++){
            set.add(my_string.substring(0,i));
        }
        
        if(set.contains(is_prefix)) return 1;
        return 0;
    }
}