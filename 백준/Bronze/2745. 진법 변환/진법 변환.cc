#include <iostream>
#include <string>

int pow(int x, int n){
    if(n == 0)  return 1;

    if(n % 2 == 0)  return pow(x*x,n/2);
    else    return x * pow(x*x,(n-1)/2);
}

int main(){
    std::string str;
    int Ans=0,B,len;
    std::cin>>str>>B;
    len = str.length();

    for(int i=0; i<len; i++){
        int temp;
        if(str[len-i-1] <= '9')   temp = str[len-i-1] - '0';
        else    temp = str[len-i-1] - 'A' + 10;

        Ans +=  temp * pow(B,i);
    }
    std::cout<<Ans;
    return 0;
}