#include <iostream>
#include <string>
#include <stack>

int check(std::string str){
    std::stack<char> s;
    int len = str.length();
    char ch;

    for(int i=0; i<len; i++){
        ch = str[i];
        if(ch=='(' || ch == '[')    s.push(ch);
        else if(ch == ')' || ch == ']'){
            if(s.empty())   return 0;
            
            if(ch == ')' && s.top() != '(') return 0;
            if(ch == ']' && s.top() != '[') return 0;

            s.pop();
        }
    }
    if(!s.empty())  return 0;
    return 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    while(1){
        std::getline(std::cin,str);
        if(str[0]=='.') break;
        if(check(str))  std::cout<<"yes"<<'\n';
        else    std::cout<<"no"<<'\n';
    }
    return 0;
}