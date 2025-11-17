import java.util.*;

class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] dp = new int[n+1][m+1];
        
        for(int r=1; r <= n; r++) {
            for(int c=1; c <= m; c++) {
                if(isPuddle(r,c,puddles)) {
                    continue;
                }
                
                if(r == 1 && c == 1){
                    dp[r][c] = 1;
                }
                else if(r == 1) {
                    dp[r][c] = dp[r][c-1] % 1000000007;
                }
                else if(c == 1) {
                    dp[r][c] = dp[r-1][c] % 1000000007;
                }
                else {
                    dp[r][c] = (dp[r-1][c] + dp[r][c-1]) % 1000000007;
                }
            }
        }
        
        return dp[n][m] % 1000000007;
    }
    
    public static boolean isPuddle(int row, int col, int[][] puddles) {
        for(int i=0; i<puddles.length; i++) {
            if(puddles[i][1] == row && puddles[i][0] == col) {
                return true;
            }
        }
        
        return false;
    }
}

/*

11에서 시작
dp[r][c] = dp[r-1][c] + dp[r][c-1];

*/
