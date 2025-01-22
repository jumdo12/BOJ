class Solution {
    public String solution(int[] numLog) {
        String answer = "";
        int size = numLog.length;
        
        for(int i=1; i<size; i++){
            int command = numLog[i] - numLog[i-1];
            if(command == 1){
                answer += "w";
            } else if(command == 10){
                answer += "d";
            } else if(command == -1){
                answer += "s";
            } else if(command == -10){
                answer += "a";
            }
        }
        
        return answer;
    }
}