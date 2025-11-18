import java.util.*;

class Solution {
    public int solution(int[] citations) {
        List<Integer> list = new ArrayList<>();
        
        for(int i=0; i<citations.length; i++) {
            list.add(citations[i]);
        }
        
        list.sort(Comparator.reverseOrder());
        
        for(int i=0; i<list.size(); i++) {
            int citation = list.get(i);
            int count = i + 1;
            
            if(citation < count) {
                return i;
            }
        }
        
        return citations.length;
    }
}

/*

발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상
나머지는 당연히 h번 이하(?). 이때 h의 최댓값이 H-index

1. 인용 수
3, 0, 6, 1, 5

2. 정렬
0, 1, 2, 3, 4
6, 5, 3, 1, 0

h번 이상 인용된 논문이 h편 이상
0. 6번 이상 인용된 논문이 6편 이상 x (6 <= 0 + 1)
1. 5번 이상 인용된 논문이 5편 이상 x (5 >= 1 + 1)
2. 3번 이상 인용된 논문이 3편 이상 o (3 >= 2 + 1)
그래서 h인 인용수를 return 3;

만약 h가 배열 안에서 안나오는 경우
0 1 2
9 8 7
0. 9번 이상 인용된 논문이 9편 이상 x (9 <= 1)
1. 8번 이상 인용된 논문이 8편 이상 x (8 <= 2)
2. 7번 이상 인용된 논문이 7편 이상 x (7 <= 3)

return n;

*/