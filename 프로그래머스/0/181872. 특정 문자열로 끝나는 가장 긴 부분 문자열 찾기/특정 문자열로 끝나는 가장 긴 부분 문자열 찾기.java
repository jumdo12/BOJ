class Solution {
    public String solution(String myString, String pat) {
        StringBuilder sb = new StringBuilder();
        sb.append(myString);
        String reversed = sb.reverse().toString();
        sb.setLength(0);
        
        sb.append(pat);
        pat = sb.reverse().toString();
        sb.setLength(0);
        
        sb.append(reversed.substring(reversed.indexOf(pat)));
        
        return sb.reverse().toString();
    }
}