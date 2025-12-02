import java.util.*;

class Solution {
    
    class Node {
        public String str;
        public int count;
        
        public Node(String str, int count) {
            this.str = str;
            this.count = count;
        }
    }
    
    public boolean canConvert(String begin, String target) {
        int count = 0;
        for(int i=0; i<begin.length(); i++) {
            if(begin.charAt(i) != target.charAt(i)) {
                count++;
            }
        }
        
        return count == 1;
    }
    
    public int solution(String begin, String target, String[] words) {
        Node node = new Node(begin, 0);
        Queue<Node> q = new ArrayDeque<>();
        int size = words.length;
        boolean[] visited = new boolean[size];
        
        q.offer(node);
        
        while(!q.isEmpty()) {
            Node curr = q.poll();
            
            if(curr.str.equals(target)) {
                return curr.count;
            }
            
            for(int i=0; i<size; i++) {
                if(!visited[i] && canConvert(curr.str, words[i])) {
                    visited[i] = true;
                    q.offer(new Node(words[i], curr.count + 1));
                }
            }
        }
        
        return 0;
    }
}