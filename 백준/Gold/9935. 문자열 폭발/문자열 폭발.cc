#include <iostream>
#include <vector>
#include <string>

int is_exp(std::vector<char>& s, std::string str){
    char ch;
    int cnt = str.length();
    int sidx, stridx;
    sidx = s.size() - 1;
    stridx = str.size() - 1;

    if(s.size() < str.size())   return 0;

    while(cnt--){
        if(s[sidx] != str[stridx])  return 0;
        sidx--;
        stridx--;
    }
    return 1;
}

int main(){
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    std::vector<char> s;
    std::string exp;
    std::string str;

    char last_ch;

    std::cin>>str;
    std::cin>>exp;

    last_ch = exp[exp.length()-1];

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        s.push_back(ch);
        if(ch == last_ch && is_exp(s,exp)){
            for(int i=0; i<exp.length(); i++){
                s.pop_back();
            }
        }
    }

    if(s.empty()){
        std::cout << "FRULA";
    }
    else{
        for(std::vector<char>::iterator it = s.begin(); it != s.end(); ++it){
            std::cout<<*it;
        }
    }

    return 0;
}