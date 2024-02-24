#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin>>str;
    int len = str.length();
    int left , right;
    int Ans = 1;

    left = 0;
    right = len-1;

    while(left < right){
        if(str[left] != str[right]){
            Ans=0;
            break;
        }
        left++;
        right--;
    }
    std::cout<<Ans;
    return 0;
}