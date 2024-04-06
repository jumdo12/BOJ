#include <iostream>
#include <stack>
#include <cmath>

int main(){
    int A,B,M,num,sum=0;
    std::stack<int> s;

    std::cin>>A>>B>>M;

    for(int i=M-1; i>=0; i--){
        std::cin>>num;
        sum += (num * pow(A,i));
    }

    while(sum){
        s.push(sum % B);
        sum /= B;
    }

    while(!s.empty()){
        std::cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}