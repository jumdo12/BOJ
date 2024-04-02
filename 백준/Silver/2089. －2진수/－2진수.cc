#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int N;
    std::string s;

    std::cin>>N;
    if(N==0){
        s += "0";
    }
    
    while(N){
        if(N % -2 == 0){
            s += "0";
            N /= -2;
        }
        else{
            s += "1";
            N = (N-1) / -2;
        }
    }
    std::reverse(s.begin(),s.end());
    std::cout<<s;
    return 0;
}