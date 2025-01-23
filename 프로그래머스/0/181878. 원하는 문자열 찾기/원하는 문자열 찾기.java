class Solution {
    public int solution(String myString, String pat) {
        if(myString.toUpperCase().contains(pat.toUpperCase())) return 1;
        return 0;
    }
}