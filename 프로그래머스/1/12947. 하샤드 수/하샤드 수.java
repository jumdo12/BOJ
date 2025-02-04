class Solution {
    public boolean solution(int x) {
        int sum = 0;
        
        String temp = String.valueOf(x);
        for(String num : temp.split("")){
            sum += Integer.parseInt(num);
        }
        
        return x % sum == 0;
    }
}