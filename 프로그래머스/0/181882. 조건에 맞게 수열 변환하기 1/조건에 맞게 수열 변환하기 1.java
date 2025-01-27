class Solution {
    public int[] solution(int[] arr) {
        int[] answer = arr;
      
        for(int i=0; i<answer.length; i++){
            int num = answer[i];
            if(num >= 50 && num % 2 == 0){
                answer[i] = num / 2;
            }
            else if(num < 50 && num % 2 != 0){
                answer[i] = num * 2;
            }
        }
        
        return answer;
    }
}