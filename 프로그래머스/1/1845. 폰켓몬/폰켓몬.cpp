#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<int> nums){
    unordered_map <int,int> m;
    
    for(auto const& num : nums) {
        m[num]++;
    }
    
    int answer = 0;
    answer = min(m.size(), nums.size() / 2);
    
    return answer;
}