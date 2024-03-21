#include <iostream>
#include <stack>
#include <string>

int main(){
    std::stack<char> s1, s2;
    std::string str;
    int len,cnt;

    std::cin>>str;
    len = str.length();

    for(int i=0; i<len; i++){
        s1.push(str[i]);
    }

    std::cin>>cnt;

    while(cnt--){
        char cmd, data;
        std::cin>>cmd;

            if(cmd == 'L'){
                if(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            else if(cmd == 'D'){
                if(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            else if(cmd == 'B'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else if(cmd == 'P'){
                std::cin>>data;
                s1.push(data);
            }
        }

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()){
        std::cout<<s2.top();
        s2.pop();
    }

    return 0;
}