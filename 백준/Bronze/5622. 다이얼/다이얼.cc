#include <iostream>
#include <string>

int func(char ch){
    if(ch < 'D')    return 3;
    else if(ch < 'G')   return 4;
    else if(ch <'J')    return 5;
    else if(ch < 'M')  return 6;
    else if(ch < 'P')   return 7;
    else if(ch < 'T')   return 8;
    else if(ch < 'W')   return 9;
    else    return 10;
}

int main(){
    std::string str;
    int len,Ans = 0;
    std::cin >> str;
    len = str.length();
    for(int i=0; i<len; i++){
        Ans += func(str[i]);
    }
    std::cout<<Ans;
    return 0;
}