class Solution {
    public int solution(int[] num_list) {
        int length = num_list.length;
    
        if(length <= 10){
            int mul = 1;
            for(int num : num_list){
                mul *= num;
            }        
            return mul;
        } else{
            int sum = 0;
            for(int num : num_list){
                sum += num;
            }
            return sum;
        }
    }
}