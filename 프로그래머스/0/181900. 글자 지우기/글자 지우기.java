class Solution {
    public String solution(String my_string, int[] indices) {
        String answer = "";
        
        for(int i=0; i<my_string.length(); i++){
            boolean found = false;
            for(int j=0; j<indices.length; j++){
                if(indices[j] == i){
                    found = true;
                    break;
                }
            }
            
            if(!found){
                answer += my_string.charAt(i);
            }
        }
        
        return answer;
    }
}