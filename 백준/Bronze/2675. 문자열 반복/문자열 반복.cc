#include <iostream>
#include <string>

int main(){
    int N ,t, len;
    std::string str;
    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> t >> str;
        len = str.length();
        for(int j = 0; j < len; j++){
            for(int k=0; k<t; k++){
                std::cout<<str[j];
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}