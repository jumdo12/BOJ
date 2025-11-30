import java.util.*;

class Solution {
    public static int count = 0;
    
    public void dfs(int[] numbers, int curr, int sum, int target) {
        if(curr == numbers.length) {
            if(sum == target) {
                count++;            
            }
            
            return;
        }
        
        dfs(numbers, curr+1, sum + numbers[curr], target);
        dfs(numbers, curr+1, sum - numbers[curr], target);
    }
    
    public int solution(int[] numbers, int target) {    
        dfs(numbers, 0, 0, target);
        
        return count;
    }
}

/*
음이 아닌 정수 n개
순서를 마꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들어야함

1,1,1,1로 3은
1 -1 1 1 1

1. 그리디
+ n개
- N-n개
를 찾는 ?

방법 수도 써야한다..?
n개 중에
+ i개
- k개
j = N-k;

+1, +1, +1, +1, +1
+1, -1, +1, +1, +1
이거라서 DFS 같은데

*/