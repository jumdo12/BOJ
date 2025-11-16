import java.util.*;

class Solution {
    static TreeMap<Integer, Integer> map = new TreeMap<>();
    
    public int[] solution(String[] operations) {
        for(var operation : operations) {
            String[] command = operation.split(" ");
            
            if(command[0].equals("I")) {
                int num = Integer.parseInt(command[1]);
                
                add(num);
            }
            else if(command[0].equals("D")) {
                if(isEmpty()) {
                    continue;
                }
                
                if(command[1].equals("1")) {
                    pollLast();
                }
                else {
                    pollFirst();
                }
            }
        }
        
        if(isEmpty()) {
            return new int[2];
        }
                
        return new int[]{map.lastKey(), map.firstKey()};
    }
    
    public static void add(int num) {
        int count = map.getOrDefault(num, 0) + 1;
        
        map.put(num, count);
    }
    
    public static boolean isEmpty() {
        return map.isEmpty();
    }
    
    public static int pollLast() {
        int last = map.lastKey();
        int count = map.get(last);
        
        if(count > 1) {
            map.put(last, count - 1);
        }
        else {
            map.remove(last);
        }
        
        return last;
    }
    
    public static int pollFirst() {
        int first = map.firstKey();
        int count = map.get(first);
        
        if(count > 1) {
            map.put(first, count - 1);
        }
        else {
            map.remove(first);
        }
        
        return first;
    }
}