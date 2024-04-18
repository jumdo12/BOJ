#include <iostream>

int main(){
    int a,b,c;
    while(1){
        std::cin>>a>>b>>c;
        int flag = 0;
        if(a == 0 || b == 0 || c == 0)  break;
        flag = (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a);
        if(flag)    std::cout<<"right"<<'\n';
        else    std::cout<<"wrong"<<'\n';
    }
    return 0;
}