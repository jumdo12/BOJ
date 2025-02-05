class Solution {
    public int solution(String[] strArr) {
        int answer = -1;
        int[] length = new int[31];
        
        for(String str: strArr){
            int leng = str.length();
            length[leng]++;
            if(length[leng] > answer) answer = length[leng];
        }
        
        
        return answer;
    }
}