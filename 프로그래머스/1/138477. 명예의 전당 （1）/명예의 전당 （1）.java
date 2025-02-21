import java.util.*;

class Solution {
    public int[] solution(int k, int[] score) {
        List<Integer> list = new ArrayList<>();
        for(int i = 1; i<=score.length; i++){
            list.add(Arrays.stream(score).limit(i).boxed().sorted(Comparator.reverseOrder()).limit(k).min(Integer::compare).orElse(0));
        }
        return list.stream().mapToInt(i->i).toArray();
    }
}