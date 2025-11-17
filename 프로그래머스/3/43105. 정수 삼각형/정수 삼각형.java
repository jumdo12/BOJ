import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int n = triangle.length;
        int[][] dp = new int[n][n];

        dp[0][0] = triangle[0][0];
        for(int r = 1; r < n; r++) {
            for(int c = 0; c <= r; c++){
                int next = c - 1;
                if(c == 0) {
                    dp[r][c] = triangle[r][c] + dp[r-1][c];
                }
                else if(c == r) {
                    dp[r][c] = triangle[r][c] + dp[r-1][c-1];
                }
                else {
                    dp[r][c] = triangle[r][c] + Math.max(dp[r-1][c], dp[r-1][c-1]);
                }
            }
        }    
        
        int max = -1;
        for(int i=0; i<n; i++) {
            max = Math.max(dp[n-1][i], max);
        }
        
        return max;
    }
}

/*

꼭대기에서 거쳐가는 숫자의 합이 가장 큰 경우
내려갈때는 대각 좌우 

0 1
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

dp[r][c] = arr[r][c] + max(dp[r-1][c], dp[r-1][c-1]);

c+1 <= i
*/