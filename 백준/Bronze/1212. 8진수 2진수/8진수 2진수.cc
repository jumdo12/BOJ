#include <iostream>
#include <string>

int main(){
    std::string oct;
    std::cin>>oct;
    int temp,flag = 0,idx;
    int buf[3] = {0};

    for(int i=0; i<oct.length(); i++){
        temp = oct[i] - '0';
        for(int i=2; i>=0; i--){
            buf[i] = temp % 2;
            temp /= 2;
        }

        for(int i=0; i<3; i++){
            if(!flag && buf[0] == 0 && buf[1] == 0){
                flag = 1;
                i+=2;
            }
            else if(!flag && buf[0] == 0){
                flag = 1;
                continue;
            }
            flag = 1;
            std::cout<<buf[i];
        }
    }

    return 0;
}