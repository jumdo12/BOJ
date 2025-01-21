class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        int pCnt = 0;
        int yCnt = 0;
        
        s = s.toLowerCase();
        for(char ch : s.toCharArray()){
            if(ch == 'p') pCnt++;
            else if(ch == 'y') yCnt++;
        }
    
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");

        
        return pCnt == yCnt;
    }
}