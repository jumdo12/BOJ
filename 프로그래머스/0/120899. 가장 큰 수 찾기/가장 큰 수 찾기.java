import java.util.*;

class Solution {
    public int[] solution(int[] array) {
        List<Tmp> list = new ArrayList<>();
        
        for(int i=0; i<array.length; i++) {
            list.add(new Tmp(array[i],i));
        }
        
        list.sort((a,b) -> Integer.compare(b.num, a.num));
        
        Tmp ans = list.get(0);
        int[] answer = {ans.num, ans.idx};
        return answer;
    }
    
    public static class Tmp {
        public int num;
        public int idx;
        
        public Tmp(int num, int idx) {
            this.num = num;
            this.idx = idx;
        }
    }
}