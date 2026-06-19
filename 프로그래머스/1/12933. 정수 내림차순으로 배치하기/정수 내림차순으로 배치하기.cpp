#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    vector<int> v;
    while(n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    
    sort(v.begin(), v.end(), greater<int>());
    string str = "";
    
    for(int num : v) {
        str += to_string(num);
    }
    
    long long answer = stoll(str);
    return answer;
}
