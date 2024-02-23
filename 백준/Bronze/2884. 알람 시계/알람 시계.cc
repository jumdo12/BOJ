#include <iostream>
int main(){
    int H,M;
    std::cin>>H>>M;
    if(M >= 45) M -= 45;
    else{
        if(H == 0){
            H = 23;
        }
        else{
            H--;
        }
        M = M + 60 - 45;
    }
    std::cout << H << " " << M;
    return 0;
}