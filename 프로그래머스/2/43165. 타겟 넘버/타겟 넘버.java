class Solution {
    private int count = 0;
    
    public int solution(int[] numbers, int target) {
        solve(numbers, 0, target, 0);
        
        return count;
    }
    
    public void solve (int[] numbers, int curr, int target, int sum) {
        if(numbers.length == curr) {
            if(sum == target) {
                count++;
            }
            
            return;
        }
        
        solve(numbers, curr+1, target, sum + numbers[curr]);
        solve(numbers, curr+1, target, sum - numbers[curr]);
    }
}

/*

n개의 정수가 있는 데 더하거나 뺴기만 해서 타겟 넘버를 만들어라

4, 1, 2, 1
4 + 1
    4 + 1 + 2
    4 + 1 - 2
        ...
4 - 1
    4 - 1 + 2
    4 - 1 - 2
        ...

뎁스가 꽉 찼을 때 타겟 넘버가 되어야함.
그냥 브루트포스
*/