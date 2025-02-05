class Solution {
    public int solution(String myString, String pat) {
        int cnt = 0;
        for(int i=0; i<myString.length() - pat.length() + 1; i++){
            String str = myString.substring(i,i+pat.length());
            System.out.println(str);
            if(str.contains(pat)) cnt++;
        }
        return cnt;
    }
}