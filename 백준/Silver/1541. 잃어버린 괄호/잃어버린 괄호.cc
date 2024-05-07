#include <iostream>
#include <string>

int main(){
    int tmp, sum, flag;
    tmp = sum = flag = 0;
    std::string str;

    std::cin>>str;

    for(int i=0; i<str.length(); i++){
        if(str[i] == '+' || str[i] == '-'){
            if(!flag){
                sum += tmp;
                tmp = 0;

                if(str[i] == '-'){
                    flag = 1;
                }
            }
            else{
                sum -= tmp;
                tmp = 0;
            }
        }
        else{
            tmp *= 10;
            tmp += (str[i] - '0');
        }
    }

    if(flag){
        sum -= tmp;
    }
    else{
        sum += tmp;
    }

    std::cout<<sum;

    return 0;
}