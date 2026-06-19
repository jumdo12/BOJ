#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int odd, even;
    odd = 0;
    even = 0;
    
    for(int num : num_list) {
        if(num % 2 == 0) {
            even++;
        } else if(num % 2 == 1) {
            odd++;
        }
    }
    
    vector<int> answer = {even, odd};
    return answer;
}