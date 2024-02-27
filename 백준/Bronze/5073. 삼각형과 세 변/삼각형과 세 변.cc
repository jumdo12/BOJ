#include <iostream>

int main(){
    int A,B,C;
    std::cin>>A>>B>>C;
    while(A!=0 && B!=0 && C!=0){
        if((A+B<=C)||(B+C)<=A||(A+C)<=B)
            std::cout << "Invalid" << std::endl;
        else if(A==B && B==C && A==C)
            std::cout << "Equilateral"<<std::endl;
        else if(A==B || B==C || A ==C)
            std::cout << "Isosceles" << std:: endl;
        else
            std::cout << "Scalene" << std::endl;
        std::cin>>A>>B>>C;
    }
    return 0;
}