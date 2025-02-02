class Solution {
    public String solution(String[] str_list, String ex) {
        String answer = "";
        
        for(String token : str_list){
            if(!token.contains(ex)){
                answer += token;
            }
        }
        
        return answer;
    }
}