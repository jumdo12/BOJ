import java.util.*;

class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) {
        List<Integer> numbers = new ArrayList<>();
        int s = slicer[0];
        int e = slicer[1];
        int f = slicer[2];
        
        if(n == 1){
            for(int i=0; i <= e; i++){
                numbers.add(num_list[i]);
            }
        } else if(n == 2){
            for(int i=s; i<num_list.length; i++){
                numbers.add(num_list[i]);
            }
        } else if(n == 3){
            for(int i=s; i<=e; i++){
                numbers.add(num_list[i]);
            }
        } else if(n == 4){
            for(int i=s; i<=e; i+=f){
                numbers.add(num_list[i]);
            }
        }
        
        return numbers.stream().mapToInt(i->i).toArray();
    }
}