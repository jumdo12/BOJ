class Solution {
    private int cnt = 0;
    
    private void dfs(int[] number, boolean[] visited, int sum, int curr, int idx){
        if(curr == 3 && sum == 0) cnt++;
        else{
            for(int i=idx; i<number.length; i++){
                if(!visited[i]){
                    visited[i] = true;
                    dfs(number,visited,sum + number[i], curr+1,i+1);
                    visited[i] = false;
                }
            }
        }
    }
    
    public int solution(int[] number) {
        boolean[] visited = new boolean[number.length];
        dfs(number,visited,0,0,0);
        return cnt;
    }
}