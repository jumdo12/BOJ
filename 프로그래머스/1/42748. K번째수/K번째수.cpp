#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        vector<int> tmp;
        for(int idx = i-1; idx <= j-1; idx++) {
            int num = array[idx];
            tmp.push_back(num);
        }
        
        sort(tmp.begin(), tmp.end());
        
        int num = tmp[k-1];
        answer.push_back(num);
    }
    
    return answer;
}