#include <iostream>

int gcd(int A, int B){
    if(B == 0)  return A;
    return gcd(B,A%B);
}

int main(){
    int A,B,C,D,GCD,temp;
    std::cin>>A>>B>>C>>D;
    GCD = gcd(B,D);
    temp = B * D / GCD;
    A *= (temp / B);
    B *= (temp / B);
    C *= (temp / D);
    D *= (temp / D);

    A += C;
    temp = gcd(A,B);
    A /= temp;
    B /= temp;

    std::cout<<A<<" "<<B;

    return 0;
}