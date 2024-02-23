#include <iostream>
int main(){
    int X,Y,Ans;
    Ans = 0;
    std::cin >> X >> Y;
    if(X < 0){
        if(Y > 0){
            Ans = 2;
        }
        else{
            Ans = 3;
        }
    }
    else{
        if(Y>0){
            Ans = 1;
        }
        else{
            Ans = 4;
        }
    }
    std::cout << Ans;
    return 0;
}