#include <iostream>
#include <string>

int idx = 0;

int recv(std::string& str){
    int sum = 0;
    int mul;

    while(idx < str.length()){
        if(str[idx] == '('){
            sum--;
            mul = str[idx-1] - '0';

            idx++;
            sum += (mul * recv(str));
        }   
        else if(str[idx] == ')'){
            idx++;
            return sum;
        }
        else{
            idx++;
            sum++;
        }
    }

    return sum;
}

int main(){
    std::string str;
    std::cin>>str;

    std::cout<<recv(str);

    return 0;
}