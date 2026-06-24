#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> m;
    for(vector<string> cloth : clothes) {
        string name = cloth[0];
        string category = cloth[1];
        
        m[category]++;
    }
    
    int tmp = 1;
    for(auto [k, v] : m) {
        tmp *= (v + 1);
        
    }
    return tmp - 1;
}
