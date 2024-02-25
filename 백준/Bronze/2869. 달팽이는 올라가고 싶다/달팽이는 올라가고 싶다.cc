#include <iostream>

int main(){
    int A,B,N,Ans;
    std::cin>>A>>B>>N;
    N -= A;
    if(N % (A-B))   Ans = N / (A - B) + 1;
    else    Ans = N / (A-B);
    Ans++;
    std::cout<<Ans;
    return 0;
}