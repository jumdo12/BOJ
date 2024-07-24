#include <iostream>
#include <string>

using namespace std;

int main(){
    string a,b,c;
    std::cin>>a>>b>>c;
    std::cout<<stoi(a)+stoi(b)-stoi(c)<<'\n';
    std::cout<<stoi(a+b) - stoi(c);
    
    return 0;
}