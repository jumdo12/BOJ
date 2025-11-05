#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> m;
    
    for(auto name : participant) {
        m[name]++;
    }
    
    for(auto name : completion) {
        m[name]--;
    }
    
    string answer = "";
    for(auto pair : m) {
        string name = pair.first;
        
        if(m[name] > 0) {
            answer = name;
        }
    }
    
    return answer;
}