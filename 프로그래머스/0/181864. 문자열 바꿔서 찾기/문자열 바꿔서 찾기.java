class Solution {
    public int solution(String myString, String pat) {
        int answer = 0;
        
        String temp = myString.replace("A","C");
        temp = temp.replace("B","A");
        temp = temp.replace("C","B");
        myString = temp;
        
        if(myString.contains(pat)) answer = 1;
        
        return answer;
    }
}