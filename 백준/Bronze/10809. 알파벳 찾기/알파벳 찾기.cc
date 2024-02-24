#include <iostream>
#include <string>

int main(){
    std::string str;
    int len , alpha[26];
    std::cin >> str;
    len = str.length();
    for(int i=0; i<26;i++){
        alpha[i] = -1;
    }

    for(int i=0; i<len; i++){
        int temp = str[i] - 97;
        if(alpha[temp] == -1) alpha[temp] = i;
    }
    for(int i=0; i<26; i++){
        std::cout<<alpha[i] <<" ";
    }
    return 0;
}