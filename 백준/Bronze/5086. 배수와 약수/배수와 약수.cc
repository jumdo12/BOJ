#include <iostream>

int main(){
    int A,B;
    std::cin>>A>>B;
    while(A != 0 && B != 0){
        if(B % A == 0)  std::cout<<"factor"<<std::endl;
        else if(A%B == 0)   std::cout<<"multiple"<<std::endl;
        else    std::cout<<"neither"<<std::endl;
        std::cin>>A>>B;
    }
    return 0;
}