class Solution {
    public String[] solution(String[] names) {
        String sum = "";
        
        for(int i=0; i<names.length; i += 5){
            sum += (names[i] + ",");
        }
        
        return sum.split(",");
    }
}