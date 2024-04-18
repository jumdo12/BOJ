#include <iostream>
#include <string>

int main(){
    std::string str;
    while(std::cin>>str){
        if(str[0] == '0')   break;

        int left = 0;
        int right = str.length() - 1;
        int flag = 0;
        while(left < right){
            if(str[left] != str[right]){
                std::cout<<"no"<<'\n';
                flag = 1;
                break;
            }
            left++;
            right--;
        }
        if(!flag){
            std::cout << "yes" << '\n';
        }
    }
    return 0;
}