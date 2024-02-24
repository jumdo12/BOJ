#include <iostream>
#include <string>

int main(){
    std::string str;
    int len,cnt=0;
    std::getline(std::cin , str);
    len = str.length();
    for(int i=0; i<len; i++){
        if (str[i] != ' ' && i + 1 == len) cnt++;
        else if (str[i] != ' ' && str[i + 1] == ' ') cnt++;
    }

    std::cout << cnt;
    return 0;
}