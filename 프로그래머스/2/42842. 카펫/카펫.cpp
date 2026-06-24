#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int row=1; row<=yellow; row++) {
        if(yellow % row != 0) {
            continue;
        }
        
        int col = yellow / row;
        
        if(row * 2 + col * 2 + 4 == brown) {
            answer.push_back(col + 2);
            answer.push_back(row + 2);
            break;
        }
    }
    
    return answer;
}

/*
노랑 갈색 갯수만 암
전체 사이즈를 구해라

노랑 row, col
row * 2 + col * 2 + 4 아닌가
1 2 3 4  6 8 9 10....
24 12 8 6 
*/