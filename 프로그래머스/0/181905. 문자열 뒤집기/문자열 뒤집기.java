class Solution {
    public String solution(String my_string, int s, int e) {
        String answer = my_string.substring(0,s);
        StringBuilder sb = new StringBuilder();
        sb.append(my_string.substring(s,e+1));
        sb.reverse();
        answer += sb.toString();
        answer += my_string.substring(e+1);
        
        return answer;
    }
}