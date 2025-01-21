class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        
        for(int i=0; i<n; i++){
            long temp = (long)(x) * i;
            answer[i] = x + temp;
        }
        
        return answer;
    }
}