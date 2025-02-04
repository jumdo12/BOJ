class Solution {
    public int solution(int num) {
        int idx = 0;
        long n = num;
        
        while(n != 1){
            idx++;
            if(n % 2 == 0){
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            
            if(idx == 500) return -1;
        }
        
        return (int)idx;
    }
}