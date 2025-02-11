class Solution {
    public String solution(String s) {
        StringBuilder answer = new StringBuilder();
        int index = 0;  // 단어 내에서의 문자 인덱스
        
        for (char ch : s.toCharArray()) {
            if (ch == ' ') {
                answer.append(ch);
                index = 0;
            } else {
                if (index % 2 == 0) {
                    answer.append(Character.toUpperCase(ch));
                } else {
                    answer.append(Character.toLowerCase(ch));
                }
                index++;
            }
        }
        
        return answer.toString();
    }
}
