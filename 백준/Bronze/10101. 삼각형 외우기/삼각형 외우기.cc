#include <iostream>

int main(){
    int A,B,C;
    std::cin>>A>>B>>C;
    if(A+B+C != 180) std::cout << "Error";
    else if((A==B)&&(B==C)&&(A==C)) std::cout << "Equilateral";
    else if((A==B)||(B==C)||(A==C)) std::cout << "Isosceles";
    else    std::cout << "Scalene";
    return 0;
}