#include <iostream>

int main(){
    int Year , Ans = 0;
    std::cin >> Year;
    if(Year % 4 == 0 &&(Year % 100 !=0 || Year % 400 == 0)){
        Ans = 1;
    }
    std::cout<<Ans;
}